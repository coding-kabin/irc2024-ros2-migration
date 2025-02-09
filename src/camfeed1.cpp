#include "rclcpp/rclcpp.hpp"
#include <image_transport/image_transport.hpp>
#include <opencv2/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream> // for converting the command line parameter to integer

int main(int argc, char** argv)
{

  ros::init(argc, argv, "image_publisher",ros::init_options::AnonymousName);
  rclcpp::Node nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("video_frame1/image", 1);

  int video_source = 0;

  cv::VideoCapture cap(video_source);
  cap.set(cv::CAP_PROP_FRAME_WIDTH,640);
  cap.set(cv::CAP_PROP_FRAME_HEIGHT,360);
  // Check if video device can be opened with the given index
  if(!cap.isOpened()) return 1;
  cv::Mat frame;
  sensor_msgs::msg::ImagePtr msg;

  rclcpp::Rate loop_rate(30);
  while (nh.ok()) {
    cap >> frame;
    // Check if grabbed frame is actually full with some content
    if(!frame.empty()) {
      msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
      pub.publish(msg);
    //  cv::waitKey(1);
    }

    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
}