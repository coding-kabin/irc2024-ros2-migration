#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16MultiArray
from sensor_msgs.msg import Joy


class JoystickControl(Node):
    def __init__(self):
        super().__init__('joystick_control_node')
        
        self.pump2 = 0  # variable to control peristalic pump 2
        self.pump3 = 0  # variable to control peristalic pump 3
        self.auger_spinC = 0  # variable to control auger spin clockwise
        self.auger_spinA = 0  # variable to control auger spin anti-clockwise
        self.auger_spin = 0
        self.msg = Int16MultiArray()
        self.stepper_status = 2  # 0 / 2 for disable, 1 for enable

        self.sub = self.create_subscription(Joy, '/joy1', self.callback, 10)
        self.pub = self.create_publisher(Int16MultiArray, '/ld_mega', 10)

    def callback(self, data):
        joy_pump2 = data.axes[-1]  # controls pumps
        joy_pump3 = data.axes[-2]
        
        square = data.buttons[3]  # enabling stepper
        circle = data.buttons[1]  # disabling stepper
        
        self.auger_spin = 0
        
        xaxis = data.axes[0]  # controls spin of augur
        if joy_pump2 == -1:
            self.pump2 = 1
        else:
            self.pump2 = 0
        if joy_pump3 == 1:
            self.pump3 = 1
        else:
            self.pump3 = 0
        
        if square == 1:
            self.stepper_status = 1
        elif circle == 1:
            self.stepper_status = 2

        if xaxis > 0:
            self.auger_spin = 1
        elif xaxis < 0:
            self.auger_spin = -1
        else:
            self.auger_spin = 0
        
        self.msg.data = [self.pump2, self.pump3, self.auger_spin, self.stepper_status]
        self.pub.publish(self.msg)


def main(args=None):
    rclpy.init(args=args)
    node = JoystickControl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
