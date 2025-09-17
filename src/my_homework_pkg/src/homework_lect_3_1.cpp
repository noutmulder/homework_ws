
/*
--Node description: 
...what the node is doing (functionally)... 
When node is created the node prints the answer to all every 1000 milliseconds   

*/ 

/*
--Software changes:
one line per change 
(1) created 31.3.2025: developer-Tilmann Koster reviewer(s)-Niek Ottens 
(2) changed 01.4.2025: xxx functionality added ... : developer-Tilmann Koster reviewer(s)-Niek Ottens 
...
*/

//-- tester: Sander Gieling


//--general includes 
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <random>
//--custom includes 
#include "std_msgs/msg/int32.hpp"       //header for the standard message that is used for communication



class RandomNumberPublisher : public rclcpp::Node
{
	public:
	//-- constuctor: 
	RandomNumberPublisher() 
    : Node("random_publisher_node"),
    rng_(std::random_device{}()),
    dist_(0, 100)
	{	
		//--communication and timer objects: 
		publisher_rng_number_ = this->create_publisher<std_msgs::msg::Int32>("rng_num",10);
		timer_rng_number_ = this->create_wall_timer(
 	    std::chrono::milliseconds(3000), 
        std::bind(&RandomNumberPublisher::timer_print_rng, this));
		
		//--customs functions:
		

	}

	//-- communication and timer functions 
	void timer_print_rng()
	{   
		message_.data = dist_(rng_);
        RCLCPP_INFO(this->get_logger(), "Publishing: %d", message_.data);
        publisher_rng_number_->publish(message_);
	}


	private:
		//--rclcpp variables:
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_rng_number_;
        rclcpp::TimerBase::SharedPtr timer_rng_number_;

		std_msgs::msg::Int32 message_;
        std::mt19937 rng_; 
        std::uniform_int_distribution<int> dist_;
};


int main(int argc,char *argv[])
{
rclcpp::init(argc,argv)	;

auto node = std::make_shared<RandomNumberPublisher>();


rclcpp::spin(node);

rclcpp::shutdown();

return 0;

}
