#include "rclcpp/rclcpp.hpp"
#include "my_homework_interfaces/msg/name_number.hpp"   // <-- include custom msg

class NameNumberPubNode : public rclcpp::Node
{
public:
  NameNumberPubNode() : Node("name_number_publisher")
  {
    publisher_ = this->create_publisher<my_homework_interfaces::msg::NameNumber>(
      "name_number_topic", 10);

    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&NameNumberPubNode::publish_message, this));
  }

private:
  void publish_message()
  {
    auto msg = my_homework_interfaces::msg::NameNumber();
    msg.name = "Nout";
    msg.number = 42;
    RCLCPP_INFO(this->get_logger(), "Publishing: name='%s' number=%d",
                msg.name.c_str(), msg.number);
    publisher_->publish(msg);
  }

  rclcpp::Publisher<my_homework_interfaces::msg::NameNumber>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NameNumberPubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
