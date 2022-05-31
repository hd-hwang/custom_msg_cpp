#include "ros/ros.h"
#include "custom_msg_cpp/custom.h"  
//메시지 추가하고서는 #inlcude "프로젝트명/실행파일.h"

#include <ctime>
#include <chrono>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc,argv, "talker");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<custom_msg_cpp::custom>("custom",10);
    //내가 정의한 메시지 유형으로 발행한다.

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        custom_msg_cpp::custom msg;
        //프로젝트명::msg파일이름 msg;

        msg.robot_name.data = "Robot_1";
        //std_msgs/String.data가 있는 것으로 추정됨. 

        auto end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        msg.date_time.data = std::ctime(&end_time);
        msg.bellid.data = 5;
        msg.location.x = 5;
        msg.location.y =5;
        msg.location.theta = 90;

        pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;
}