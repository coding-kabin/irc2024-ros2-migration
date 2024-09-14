#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Int16MultiArray

class TestDriveNode(Node):
    def __init__(self):
        super().__init__('test_drive_node')
        self.get_logger().warn("ENTERING TESTING SCRIPT")
        
        # Publishers
        self.pub_rover = self.create_publisher(Point, '/rover', 10)
        self.pub_cam_gimble = self.create_publisher(Point, '/cam_gimble', 10)
        self.pub_control2 = self.create_publisher(Int16MultiArray, '/control2', 10)
        self.pub_control1 = self.create_publisher(Int16MultiArray, '/control1', 10)

        # Testing Drive
        self.get_logger().info("CHECKING DRIVE")
        self.test_drive()
        self.get_logger().info("FINISHED CHECKING DRIVE")
        
        # Testing Gimbal
        self.get_logger().info("CHECKING GIMBAL")
        self.test_gimbal()
        self.get_logger().info("FINISHED CHECKING GIMBAL")
        
        # Testing Arm: Base and Bevel
        self.get_logger().info("CHECKING ARM : BASE AND BEVEL")
        self.test_arm_base_bevel()
        self.get_logger().info("FINISHED CHECKING ARM : BASE AND BEVEL")
        
        # Testing Arm: Linear Actuators 1 and 2
        self.get_logger().info("CHECKING ARM : LINEAR ACTUATORS 1 AND 2")
        self.test_arm_linear_actuators()
        self.get_logger().info("FINISHED CHECKING ARM : LINEAR ACTUATORS 1 AND 2")
        
        # Testing Gripper
        self.get_logger().info("CHECKING GRIPPER")
        self.test_gripper()
        self.get_logger().info("FINISHED CHECKING GRIPPER")
        
        self.get_logger().warn("EXITING TESTING SCRIPT")

    def test_drive(self):
        point = Point()
        point.x = 15
        point.z = 15
        for _ in range(2):
            self.pub_rover.publish(point)
            time.sleep(1)
        point.x = 0
        point.z = 0
        self.pub_rover.publish(point)
        time.sleep(1)
        point.x = -15
        point.z = -15
        for _ in range(2):
            self.pub_rover.publish(point)
            time.sleep(1)
        point.x = 0
        point.z = 0
        self.pub_rover.publish(point)
        time.sleep(1)
        point.x = 15
        point.z = -15
        for _ in range(2):
            self.pub_rover.publish(point)
            time.sleep(1)
        point.x = 0
        point.z = 0
        self.pub_rover.publish(point)
        time.sleep(1)
        point.x = -15
        point.z = 15
        for _ in range(2):
            self.pub_rover.publish(point)
            time.sleep(1)
    
    def test_gimbal(self):
        point = Point()
        point.x = 1
        point.y = 0
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = -1
        point.y = 0
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = 1
        point.y = 0
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = 0
        point.y = 1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = 0
        point.y = -1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = 0
        point.y = 1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = 1
        point.y = 1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = -1
        point.y = -1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = 1
        point.y = -1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
        point.x = -1
        point.y = 1
        for _ in range(2):
            self.pub_cam_gimble.publish(point)
            time.sleep(1)
    
    def test_arm_base_bevel(self):
        msg = Int16MultiArray()
        msg.data = [1, 125, 0, 0, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)
        msg.data = [2, 125, 0, 0, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)
        msg.data = [1, 125, 0, 0, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)
        msg.data = [0, 0, 1, 125, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)
        msg.data = [0, 0, 2, 125, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)
        msg.data = [0, 0, 3, 125, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)
        msg.data = [0, 0, 4, 125, 0]
        for _ in range(2):
            self.pub_control2.publish(msg)
            time.sleep(1)

    def test_arm_linear_actuators(self):
        msg = Int16MultiArray()
        msg.data = [255, 0, 0]
        for _ in range(2):
            self.pub_control1.publish(msg)
            time.sleep(1)
        msg.data = [-255, 0, 0]
        for _ in range(2):
            self.pub_control1.publish(msg)
            time.sleep(1)
        msg.data = [0, 255, 0]
        for _ in range(2):
            self.pub_control1.publish(msg)
            time.sleep(1)
        msg.data = [0, -255, 0]
        for _ in range(2):
            self.pub_control1.publish(msg)
            time.sleep(1)

    def test_gripper(self):
        msg = Int16MultiArray()
        msg2 = Int16MultiArray()
        msg.data = [0, 0, 2]
        msg2.data = [0, 0, 0, 0, 1]
        for _ in range(2):
            self.pub_control1.publish(msg)
            self.pub_control2.publish(msg2)
            time.sleep(1)
        msg2.data = [0, 0, 0, 0, 2]
        for _ in range(2):
            self.pub_control1.publish(msg)
            self.pub_control2.publish(msg2)
            time.sleep(1)
        msg.data = [0, 0, 0]
        msg2.data = [0, 0, 0, 0, 0]
        for _ in range(2):
            self.pub_control1.publish(msg)
            self.pub_control2.publish(msg2)
            time.sleep(1)

def main(args=None):
    rclpy.init(args=args)
    node = TestDriveNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
