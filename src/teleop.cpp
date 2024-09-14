#include <sensor_msgs/msg/joy.hpp>
#include <geometry_msgs/msg/point.hpp>
#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/int8.hpp>

class Teleop : public rclcpp::Node
{
public:
    Teleop() : Node("teleop")
    {
        // Initialize the publishers and subscriber
        vel_pub_ = this->create_publisher<geometry_msgs::msg::Point>("/rover", 20);
        // color_pub_ = this->create_publisher<std_msgs::msg::Int8>("/led", 20);
        sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy0", 20, std::bind(&Teleop::joyCallback, this, std::placeholders::_1));
    }

private:
    void teleop(float linear, float rotational, float speed)
    {
        rover_.x = (linear * ((speed + 1) / 2) + rotational * ((speed + 1) / 2)) * 100;
        rover_.z = (linear * ((speed + 1) / 2) - rotational * ((speed + 1) / 2)) * 100;

        vel_pub_->publish(rover_);
    }

    void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg)
    {
        if (msg->axes[1] > 0.1 || msg->axes[1] < -0.1 || msg->axes[0] > 0.1 || msg->axes[0] < -0.1)
        {
            teleop(msg->axes[1], msg->axes[0], msg->axes[2]);
        }
        else
        {
            rover_.x = 0;
            rover_.z = 0;
            vel_pub_->publish(rover_);
        }
        // led_.data = 0;
        // color_pub_->publish(led_);
    }

    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr vel_pub_;
    // rclcpp::Publisher<std_msgs::msg::Int8>::SharedPtr color_pub_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_;
    geometry_msgs::msg::Point rover_;
    // std_msgs::msg::Int8 led_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Teleop>());
    rclcpp::shutdown();
    return 0;
}
