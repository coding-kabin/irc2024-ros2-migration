#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import cv2
from pyzbar.pyzbar import decode

class QRCodeDecoder(Node):
    def __init__(self):
        super().__init__('qrcode_decoder_node')
        self.cap = None
        self.timer = self.create_timer(0.05, self.timer_callback)  # Set timer to 20 Hz

    def set_video_source(self, video_source):
        self.cap = cv2.VideoCapture(video_source)

    def timer_callback(self):
        if self.cap is not None and self.cap.isOpened():
            ret, frame = self.cap.read()
            if ret:
                self.decoder(frame)

    def decoder(self, image):
        gray_img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        barcode = decode(gray_img)

        for obj in barcode:
            barcode_data = obj.data.decode("utf-8")
            self.get_logger().info(f"Barcode: {barcode_data}")

def main(args=None):
    rclpy.init(args=args)
    node = QRCodeDecoder()
    
    video_source = int(input("Enter Video Number: "))
    node.set_video_source(video_source)
    
    rclpy.spin(node)

    node.cap.release()  # Release the video capture object
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
