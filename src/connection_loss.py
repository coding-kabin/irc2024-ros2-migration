#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import os
import time

hostname = "192.168.1.11"
linear = 0
angular = 0

class ConnectionLossNode(Node):
    def __init__(self):
        super().__init__('connection_loss')
        self.sub = self.create_subscription(Twist, '/rover', self.callback, 10)
        self.pub = self.create_publisher(Twist, '/rover', 10)
        self.linear = 0
        self.angular = 0
        self.timer = self.create_timer(1.0, self.check_connection)  # Timer to call check_connection every second

    def callback(self, msg):
        global linear, angular
        self.linear = -msg.linear.x
        self.angular = -msg.angular.z

    def check_connection(self):
        vels = Twist()
        vels.linear.x = self.linear
        vels.angular.z = self.angular
        response = os.system("ping -c 1 -W 3 " + hostname)
        if response == 0:
            self.get_logger().info(f'{hostname} is up!')
        else:
            self.sub.destroy()  # Unregister the subscriber
            self.pub.publish(Twist())  # Publish an empty Twist message
            time.sleep(2)
            self.pub.publish(vels)  # Publish the velocity
            time.sleep(4)

            while response:
                self.pub.publish(Twist())
                response = os.system("ping -c 1 -W 3 " + hostname)

def main(args=None):
    rclpy.init(args=args)
    node = ConnectionLossNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
