/**
 * @file  UR5Control.cpp
 * @brief File With the definitions of the UR5Control class
 * methods.
 *
 * @author RajendraMayavan
 * @copyright MIT License
 * 
 * Copyright (c) 2019 Mayavan
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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