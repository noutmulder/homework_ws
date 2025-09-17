cmake_minimum_required(VERSION 3.8)
project(my_homework_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)   # nodig als er een actionserver node wordt gemaakt 

find_package(std_msgs REQUIRED)        # gebruik maken von standaard messages
# find_package(templates_interfaces REQUIRED)   # gebruik maken van project messages 


## 1 new line name of executalbe use the program name !
add_executable(template_general src/template_general.cpp) 
add_executable(homework_lect_2_1 src/homework_lect_2_1.cpp) 
add_executable(homework_lect_2_2 src/homework_lect_2_2.cpp) 
add_executable(homework_lect_3_1 src/homework_lect_3_1.cpp) 
add_executable(homework_lect_3_2 src/homework_lect_3_2.cpp) 
# add_executable(template_publisher src/template_publisher.cpp) 
# add_executable(template_subscriber src/template_subscriber.cpp) 
# add_executable(template_serviceserver src/template_serviceserver.cpp) 
# add_executable(template_serviceclient src/template_serviceclient.cpp)
# add_executable(template_actionserver src/template_actionserver.cpp)
# add_executable(template_actionclient src/template_actionclient.cpp)


## 2 new line meaning that this program needs rclcpp
ament_target_dependencies(template_general rclcpp  )
ament_target_dependencies(homework_lect_2_1 rclcpp  )
ament_target_dependencies(homework_lect_2_2 rclcpp  )
ament_target_dependencies(homework_lect_2_2 rclcpp  )
ament_target_dependencies(homework_lect_3_1 rclcpp std_msgs )
ament_target_dependencies(homework_lect_3_2 rclcpp std_msgs )

# ament_target_dependencies(template_walltimer rclcpp  ) 
# ament_target_dependencies(template_publisher rclcpp std_msgs) 
# ament_target_dependencies(template_subscriber rclcpp std_msgs) 
# ament_target_dependencies(template_serviceserver rclcpp std_msgs templates_interfaces ) 
# ament_target_dependencies(template_serviceclient rclcpp std_msgs templates_interfaces ) 
# ament_target_dependencies(template_actionserver rclcpp rclcpp_action templates_interfaces ) 
# ament_target_dependencies(template_actionclient rclcpp rclcpp_action templates_interfaces ) 

# ## new 3 get 
install (TARGETS
	  template_general
    homework_lect_2_1
    homework_lect_2_2
    homework_lect_3_1
    homework_lect_3_2
          # template_walltimer
          # template_publisher
          # template_subscriber
          # template_serviceserver
          # template_serviceclient
          # template_actionserver
          # template_actionclient
          DESTINATION lib/${PROJECT_NAME}
          )



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()




