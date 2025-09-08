/*
--Node description:
This node demonstrates measuring elapsed time.
When created, it sleeps for ~20.088778567 seconds,
then prints the current system time and the elapsed time.
*/

//--general includes
#include <chrono>
#include <cstdint>
#include "rclcpp/rclcpp.hpp"

//--Node class
class ClockNode : public rclcpp::Node
{
public:
    ClockNode()
    : Node("clock_node")
    {
        // Total sleep duration: 20 seconds + 88,778,567 nanoseconds
        const int64_t total_nanoseconds = 20LL * 1000000000LL + 88778567LL;

        auto start = this->get_clock()->now();

        rclcpp::sleep_for(std::chrono::nanoseconds(total_nanoseconds));

        auto end = this->get_clock()->now();

        // Log current system time (integer seconds + nanoseconds remainder)
        RCLCPP_INFO(
            this->get_logger(),
            "Current system time: %ld.%09ld",
            static_cast<int64_t>(end.seconds()),
            end.nanoseconds() % 1000000000
        );

        // Calculate and log elapsed time
        const int64_t elapsed_ns = end.nanoseconds() - start.nanoseconds();
        RCLCPP_INFO(
            this->get_logger(),
            "Elapsed time: %ld seconds and %ld nanoseconds",
            elapsed_ns / 1000000000,
            elapsed_ns % 1000000000
        );
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ClockNode>();
    rclcpp::shutdown();
    return 0;
}
