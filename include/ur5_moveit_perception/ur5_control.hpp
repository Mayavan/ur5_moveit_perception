#include "ros/ros.h"
#include <moveit/move_group_interface/move_group_interface.h>

class UR5Control
{
private:
    moveit::planning_interface::MoveGroupInterface ur5_;
    geometry_msgs::Pose offset_goal;

public:
    UR5Control();
    bool grabFruit(geometry_msgs::Pose goal);
};