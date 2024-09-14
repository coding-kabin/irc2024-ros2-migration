#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16MultiArray
from irc2024.msg import sensor_msg
from irc2024.msg import atmos_msg


class SensorSubscriber(Node):
    def __init__(self):
        super().__init__('ld_sensor_subscriber')

        # Create publishers for sensor_msg and atmos_msg messages
        self.sensor_pub = self.create_publisher(sensor_msg, 'sensor_topic', 10)
        self.atmos_pub = self.create_publisher(atmos_msg, 'atmos_topic', 30)

        # Subscribe to ld_sensor_data topic
        self.create_subscription(Int16MultiArray, 'ld_sensor_data', self.ld_sensor_callback, 10)

    def ld_sensor_callback(self, data):
        # Extract values from Int16MultiArray
        co_values = data.data[0]
        ch4_values = data.data[1]
        co2_values = data.data[2]
        temp = data.data[3] / 100
        humid = data.data[4] / 100
        air_pressure = (data.data[5] * 0.0009869233) / 10  # convert from hpa to atm

        # Create sensor_msg message
        sensor_data = sensor_msg()
        sensor_data.co2 = float(co2_values)
        sensor_data.ch4 = float(ch4_values)
        sensor_data.co = float(co_values)

        # Create atmos_msg message
        atmos_data = atmos_msg()
        atmos_data.temp = float(temp)
        atmos_data.humidity = float(humid)
        atmos_data.pressure = float(air_pressure)

        # Publish sensor_msg and atmos_msg messages
        self.sensor_pub.publish(sensor_data)
        self.atmos_pub.publish(atmos_data)


def main(args=None):
    rclpy.init(args=args)
    node = SensorSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
