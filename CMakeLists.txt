cmake_minimum_required(VERSION 3.5)
project(irc2024)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find ament_cmake and other packages
find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Declare message and service files
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SpectroMsg.msg"
  "msg/SensorMsg.msg"
  "msg/AtmosMsg.msg"
  DEPENDENCIES std_msgs
)

# Specify include directories
include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

# Declare C++ executables
add_executable(teleop src/teleop.cpp)
add_executable(camfeed1 src/camfeed1.cpp)
add_executable(camfeed2 src/camfeed2.cpp)
add_executable(camfeed3 src/camfeed3.cpp)
add_executable(videofeed1 src/videofeed1.cpp)
add_executable(videofeed2 src/videofeed2.cpp)
add_executable(videofeed3 src/videofeed3.cpp)
add_executable(base_control src/base_control.cpp)

# Specify dependencies for executables
ament_target_dependencies(teleop
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
)

ament_target_dependencies(camfeed1
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

ament_target_dependencies(camfeed2
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

ament_target_dependencies(camfeed3
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

ament_target_dependencies(videofeed1
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

ament_target_dependencies(videofeed2
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

ament_target_dependencies(videofeed3
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

ament_target_dependencies(base_control
  "std_msgs"
  "rclcpp"
  "geometry_msgs"
  "sensor_msgs"
  "nav_msgs"
  "image_transport"
  "cv_bridge"
  "OpenCV"
)

# Install targets
install(TARGETS
  teleop
  camfeed1
  camfeed2
  camfeed3
  videofeed1
  videofeed2
  videofeed3
  base_control
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

# Export dependencies
ament_export_dependencies(cv_bridge image_transport geometry_msgs nav_msgs rclcpp rclpy sensor_msgs std_msgs)

# Register package
ament_package()
