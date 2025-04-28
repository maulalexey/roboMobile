cmake_minimum_required(VERSION 3.0.2)
project(motor_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(motor_controller_node src/motor_controller.cpp)
target_link_libraries(motor_controller_node ${catkin_LIBRARIES} wiringPi)
