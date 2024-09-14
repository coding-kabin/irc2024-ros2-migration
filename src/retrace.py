#!/usr/bin/env python3

import subprocess
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class RemoteConnectionManager(Node):
    def __init__(self):
        super().__init__('remote_connection_manager')
        self.remote_device_ip = "192.168.1.10"  # Replace with your remote device IP
        self.gps_positions = []  # Store past GPS positions, format: [(latitude, longitude), ...]

        # Set up ROS2 publisher for retracing path
        self.path_retrace_pub = self.create_publisher(String, '/rover', 10)

        # Subscribe to GPS data
        self.create_subscription(String, '/mavros/gpsstatus/gps1/raw', self.gps_callback, 10)
        self.create_subscription(String, '/mavros/gpsstatus/gps1/raw', self.current_gps, 10)

    def ping_remote_device(self):
        try:
            subprocess.check_output(["ping", "-c", "1", self.remote_device_ip])
            return True
        except subprocess.CalledProcessError:
            return False

    def start_monitoring(self):
        rate = self.create_rate(1)  # Adjust the rate as needed
        while rclpy.ok():
            if not self.ping_remote_device():
                self.get_logger().warn("Connection lost! Retracing path to reestablish connection.")
                self.retrace_path()
            rate.sleep()

    def retrace_path(self):
        # Use the stored GPS positions to retrace the path
        for position in reversed(self.gps_positions):
            msg = String()
            msg.data = f"Retracing to: {position}"
            self.path_retrace_pub.publish(msg)

            # Add logic here to attempt to reestablish connection using the retraced GPS position

    def gps_callback(self, msg):
        # Assuming GPS data is published on topic '/mavros/gpsstatus/gps1/raw'
        latitude, longitude = msg.data.split(',')
        self.gps_positions.append((float(latitude), float(longitude)))

    def current_gps(self, msg):
        # Assuming GPS data is published on topic '/mavros/gpsstatus/gps1/raw'
        latitude, longitude = msg.data.split(',')
        return (latitude, longitude)


def main(args=None):
    rclpy.init(args=args)
    remote_connection_manager = RemoteConnectionManager()

    # Start monitoring the remote connection
    remote_connection_manager.start_monitoring()

    rclpy.spin(remote_connection_manager)

    remote_connection_manager.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
