#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16MultiArray
from sensor_msgs.msg import Joy


class JoystickControl(Node):
    def __init__(self):
        super().__init__('joystick_control_node')

        self.pump1 = 0  # variable to control peristalic pump 1
        self.auger_up = 0  # variable to control auger up
        self.auger_down = 0  # variable to control auger down
        self.mixer_clock = 0  # variable to control mixer clockwise
        self.mixer_anti = 0  # variable to control mixer anticlockwise
        self.var_st = 0  # variable to control gripper
        self.msg = Int16MultiArray()
        
        self.sub = self.create_subscription(Joy, '/joy1', self.callback, 10)
        self.pub = self.create_publisher(Int16MultiArray, '/ld_uno', 10)
        
    def callback(self, data):
        joy_pump1 = data.axes[-1]  # controls pump 1

        xAxis1 = data.axes[3]  # controls mixer
        yAxis1 = data.axes[4]  # controls auger

        triangle = data.buttons[2]  # controls Stepper (for forward)
        cross = data.buttons[0]
        
        # Control pump 1
        if joy_pump1 == 1:
            self.pump1 = 1
        else:
            self.pump1 = 0
        
        # Control mixer and auger
        if yAxis1 > 0 and abs(yAxis1) > abs(xAxis1):
            self.auger_up = 1
        else:
            self.auger_up = 0
        if yAxis1 < 0 and abs(yAxis1) > abs(xAxis1):
            self.auger_down = 1
        else:
            self.auger_down = 0
        if xAxis1 > 0 and abs(xAxis1) > abs(yAxis1):
            self.mixer_clock = 1
        else:
            self.mixer_clock = 0
        if xAxis1 < 0 and abs(xAxis1) > abs(yAxis1):
            self.mixer_anti = 1
        else:
            self.mixer_anti = 0

        # Control gripper
        if triangle == 1:
            self.var_st = 1
        elif cross == 1:
            self.var_st = 2
        else:
            self.var_st = 0

        self.msg.data = [self.pump1, self.auger_up, self.auger_down, self.mixer_clock, self.mixer_anti, self.var_st]
        self.pub.publish(self.msg)


def main(args=None):
    rclpy.init(args=args)
    node = JoystickControl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
