#include "ur5_moveit_perception/ur5_control.hpp"
#include "ros/ros.h"
#include <moveit/move_group_interface/move_group_interface.h>

UR5Control::UR5Control() : ur5_("manipulator") 
{
  ur5_.setPlannerId("ESTkConfigDefault");
}

bool UR5Control::grabFruit(geometry_msgs::Pose goal)
{
  offset_goal = goal;
  offset_goal.position.x -= 0.5;
  ur5_.setPoseTarget(offset_goal);
  ur5_.move();
  ROS_INFO_STREAM("Move to Offset");
  ros::Duration(5).sleep();

  ur5_.setPoseTarget(goal); 
  ur5_.move();
  ROS_INFO_STREAM("Move to Goal");
  ros::Duration(5).sleep();

  ur5_.setPoseTarget(offset_goal); 
  ur5_.move();
  ROS_INFO_STREAM("Move to Offset");
  ur5_.move();
}