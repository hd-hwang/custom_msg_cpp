cmake_minimum_required(VERSION 3.0.2)
project(custom_msg_cpp)


#*패키지에 관련된 메시지를 적는다. *#
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation      #이거 꼭 추가
  roscpp
  std_msgs      #주로 이안에 메세지 거의 다 있다. 
)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   custom.msg     #사용하려는 메시지 유형을 적는다. 
#   Message2.msg
 )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs 
  )

catkin_package(

)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(custom_cpp src/custom_script.cpp)


add_dependencies(custom_cpp ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(custom_cpp
  ${catkin_LIBRARIES}
  )