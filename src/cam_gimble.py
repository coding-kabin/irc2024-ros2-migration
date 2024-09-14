#!/usr/bin/env python3
import rclpy
from rclpy import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Point

p=Point()


class CamGimbleNode(Node):
    def __init__(self):
        super().__init__('cam_gimble')
        self.publisher = self.create_publisher(Point, '/cam_gimble', 10)
        self.subscription = self.create_subscription(
            Joy,
            '/joy0',
            self.callback,
            10
        )
        self.subscription  # prevent unused variable warning

    def callback(self, msg):
        p = Point()
        p.x = msg.axes[8]
        p.y = -msg.axes[9]
        self.publisher.publish(p)

def main(args=None):
    rclpy.init(args=args)
    node = CamGimbleNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()