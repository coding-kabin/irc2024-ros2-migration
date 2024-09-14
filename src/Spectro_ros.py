#!/usr/bin/env python3

import serial
import rclpy
from rclpy.node import Node
from irc2024.msg import spectro_msg


class SpectrometerNode(Node):
    def __init__(self):
        super().__init__('spectrometer_node')

        # Define the serial port and baud rate
        self.ser = serial.Serial('/dev/ttyUSB0', 115200)  # Update the port accordingly

        # Create the publisher
        self.pub = self.create_publisher(spectro_msg, '/spectrometer', 10)
        
        # Create a timer to call the read_serial method at a fixed interval
        self.timer = self.create_timer(0.1, self.read_serial)

    def read_serial(self):
        if not self.ser.is_open:
            return
        
        try:
            data = self.ser.readline().decode('utf-8').strip()
            reading = []
            meow = ""

            for c in data:
                if c == ',' and meow != "":
                    reading.append(round(float(meow), 2))
                    meow = ""
                else:
                    meow += c

            if reading:
                pub_val = spectro_msg()
                pub_val.brad = -1
                self.pub.publish(pub_val)
                # Publish the message
                for i in reading:
                    print(i)
                    pub_val.brad = i
                    self.pub.publish(pub_val)
                    self.get_logger().info(f'Published: {i}')
                else:
                    pub_val.brad = -1
                    self.pub.publish(pub_val)

        except Exception as e:
            self.get_logger().error(f'Error reading serial data: {e}')

    def close_serial(self):
        if self.ser.is_open:
            self.ser.close()
            self.get_logger().info('Serial connection closed.')


def main(args=None):
    rclpy.init(args=args)
    node = SpectrometerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.close_serial()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
