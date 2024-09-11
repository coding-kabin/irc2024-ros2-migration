'''
This code is now obsolete
Everything contained in Spectro_ros.py script
'''

import rospy
import time
from std_msgs.msg import Float32MultiArray
from  gui_stuff.msg import *

def sub_call(data):
    pub_val = spectro_msg()
    
    for i in data.data:
        print(i)
        pub_val.brad = i
        pub.publish(pub_val)
        rate.sleep()
    else:
        pub_val.brad = -1
        pub.publish(pub_val)
        # time.sleep(1)

rclpy.init()

node = rclpy.create_node("Gui_interface_node", anonymous=True)

pub = node.create_publisher(spectro_msg, queue_size=10, "/spectrometer")
rate = rospy.Rate(10)

sub = node.create_subscription(Float32MultiArray, "/topic", sub_call)
rospy.spin()
