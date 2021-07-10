#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Acquire");
  ros::NodeHandle n;
  ros::Publisher trigger_pub = n.advertise<std_msgs::String>("master_trigger", 1);
  ros::Rate loop_rate(10);
  int count = 0;
  
  while (ros::ok()){
    std_msgs::String msg;
    std::stringstream ss;
    ss << "" << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    trigger_pub.publish(msg);
    loop_rate.sleep();
    
    ++count;
  }
  return 0;
}