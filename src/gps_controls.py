#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
import utm
import matplotlib.pyplot as plt

class GPSWaypointVisualizer(Node):

    def __init__(self):
        super().__init__('gps_waypoint_visualizer')

        self.declare_parameter('start_lat', 38.9948541)
        self.declare_parameter('start_lon', -110.1614736)

        self.odom_sub = self.create_subscription(
            NavSatFix,
            '/mavros/global_position/global',
            self.gps_cb,
            10
        )

        self.cur_east = 0.0
        self.cur_north = 0.0
        self.gps_cnt = 0
        self.set_gps = False

        # Wait for GPS data to initialize
        while not self.set_gps and rclpy.ok():
            rclpy.spin_once(self)

        self.get_logger().info('Done initializing Subscriber')

    def gps_cb(self, msg):
        self.gps_cnt += 1

        if self.gps_cnt <= 100:
            self.start_lat = msg.latitude
            self.start_lon = msg.longitude
            self.get_logger().info(f'GPS set at {self.start_lat}, {self.start_lon}')
        else:
            self.set_gps = True
            self.cur_east, self.cur_north, _, _ = utm.from_latlon(msg.latitude, msg.longitude)

    def main(self, goal_x, goal_y, start_east, start_north):
        plt_goalx = goal_x - self.cur_east
        plt_goaly = goal_y - self.cur_north
        plt_goaly[0] = 0
        plt_goalx[0] = 0
        plt.plot(plt_goalx, plt_goaly)
        plt.scatter(plt_goalx, plt_goaly, label="GPS Waypoints", color="green")
        plt.scatter([0], [0], label="Current Position", color="cyan")
        plt.legend()

        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('Visualization started')
        rclpy.spin(self)

    def timer_callback(self):
        plt.scatter([self.cur_east - self.start_east], [self.cur_north - self.start_north], label="Current Position", color="cyan")
        plt.pause(0.001)

def main(args=None):
    rclpy.init(args=args)
    node = GPSWaypointVisualizer()

    # Read coordinates
    co_file = open("/home/anshulraje/Desktop/root_cont_coordinates.txt", "r")
    lines = co_file.readlines()

    start_lat = node.get_parameter('start_lat').get_parameter_value().double_value
    start_lon = node.get_parameter('start_lon').get_parameter_value().double_value

    start_east, start_north, _, _ = utm.from_latlon(start_lat, start_lon)
    goal_x = [0]
    goal_y = [0]

    for line in lines:
        easting, northing, _, _ = utm.from_latlon(float(line.split()[0]), float(line.split()[1]))
        goal_x.append(float(easting))
        goal_y.append(float(northing))

    co_file.close()

    node.main(goal_x, goal_y, start_east, start_north)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
