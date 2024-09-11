#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/joy.hpp>
#include <std_msgs/msg/int32.hpp>

std_msgs::msg::Int32 command;

class Base{
    private:
        rclcpp::Node nh;
        ros::Publisher base_pub;
        ros::Subscriber sub;
    public:
        Base(){
            this->base_pub = this->nh.advertise<std_msgs::msg::Int32>("/base", 20);
            this->sub = this->nh.subscribe("/joy0", 20, &Base::joyCallback, this);
        }

        void joyCallback(const sensor_msgs::msg::Joy& msg){
            if(msg.axes[8] == -1)
                command.data = 1;
            else if(msg.axes[8] == 1)
                command.data = -1;
            else
                command.data = 0;

            this->base_pub.publish(command);
        }
};

int main(int argc, char **argv){
  ros::init(argc, argv, "base_control", ros::init_options::AnonymousName);
  Base base = Base();
  rclcpp::spin(node);
  return 0;
}