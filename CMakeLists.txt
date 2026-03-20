
cmake_minimum_required(VERSION 3.0.2)
project(using_markers)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
  visualization_msgs
)


add_message_files(
  FILES
  SimplifiedMarkerMsg.msg
)

##
generate_messages(
  DEPENDENCIES
  visualization_msgs
  geometry_msgs
  std_msgs
)

## catkin specific configuration
catkin_package(
  CATKIN_DEPENDS message_runtime roscpp visualization_msgs geometry_msgs
)

###########
## Build ##
###########

## Specify locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}  
)


add_executable(basic_shapes src/basic_shapes.cpp src/Marker_Library.cc)


target_link_libraries(basic_shapes ${catkin_LIBRARIES})


target_include_directories(basic_shapes PUBLIC ${CMAKE_SOURCE_DIR}/src)
