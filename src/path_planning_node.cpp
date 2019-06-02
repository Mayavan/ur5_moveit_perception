#include "ur5_moveit_perception/getTarget.h"
#include "ur5_moveit_perception/ur5_control.hpp"
#include "ros/ros.h"

#include <ur5_moveit_perception/ARMarker.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "path_planner");
 
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ur5_moveit_perception::getTarget>("ar_pose_service");
  ur5_moveit_perception::getTarget srv;
  if (client.call(srv))
  {
    ROS_INFO_STREAM(srv.response.msg.pose.pose.position.x << " " << srv.response.msg.pose.pose.position.y << " " << srv.response.msg.pose.pose.position.z);
  }
  else
  {
    ROS_ERROR("Failed to call service ar_pose_service");
    return 1;
  }

  UR5Control controller;

  controller.grabFruit(srv.response.msg.pose.pose);
  
  return 0;
}
