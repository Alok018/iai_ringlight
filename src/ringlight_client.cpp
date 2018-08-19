#include "ros/ros.h"
#include "iai_ringlight/iai_ringlight_in.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: iai_ringlight_in_client + char X Y 'a'");
    ROS_INFO("usage: iai_ringlight_in_client  char X Y ");
    return 1;
  }

  ros::NodeHandle n;
//  ros::ServiceClient client = n.serviceClient<iai_ringlight::iai_ringlight_in>("add_two_ints");
  ros::ServiceClient client = n.serviceClient<iai_ringlight::iai_ringlight_in>("IAI_ringlight_controller");
  iai_ringlight::iai_ringlight_in srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
//  srv.request.c = atoll(argv[3]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service IAI_ringlight_controller");
    return 1;
  }

  return 0;
}