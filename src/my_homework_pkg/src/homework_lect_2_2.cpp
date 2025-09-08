/*
--Node description:
This node alternates between reporting system time and steady time.
Every 5 seconds, it prints the current time from one clock,
then switches to the other for the next cycle.
*/

//--general includes
#include <chrono>
#include <cstdint>
#include "rclcpp/rclcpp.hpp"

//--Node class
class AlternatingNode : public rclcpp::Node
{
public:
    AlternatingNode()
    : Node("alternating_clock_node"),
      use_system_time_(true),
      system_clock_(RCL_SYSTEM_TIME),
      steady_clock_(RCL_STEADY_TIME)
    {
        timer_ = this->create_wall_timer(
            std::chrono::seconds(5),
            std::bind(&AlternatingNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        const auto & clock = use_system_time_ ? system_clock_ : steady_clock_;
        const auto now = clock.now();

        RCLCPP_INFO(
            this->get_logger(),
            "%s: %ld.%09ld",
            use_system_time_ ? "SYSTEM TIME" : "STEADY TIME",
            static_cast<int64_t>(now.seconds()),
            now.nanoseconds() % 1000000000
        );

        use_system_time_ = !use_system_time_;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    bool use_system_time_;
    rclcpp::Clock system_clock_;
    rclcpp::Clock steady_clock_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AlternatingNode>());
    rclcpp::shutdown();
    return 0;
}
