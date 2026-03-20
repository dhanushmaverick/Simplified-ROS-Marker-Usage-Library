#include <iostream>
#include <cstdlib>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "Marker_Library.hpp"

int main( int argc, char** argv )
{
    ros::init(argc, argv, "basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  while (ros::ok())
  {

    //
    Sphere Sphere_1;
    Sphere_1.set_position(0.0,0.0);
    Sphere_1.set_orientation(0.0,0.0,0.0,1.0);
    Sphere_1.set_scale(1.0,1.0,1.0);
    Sphere_1.set_colour(1.0,1.0,0.0);
    visualization_msgs::Marker marker1 = Sphere_1;

    //or
    Cube Cube_1;
    Cube_1.set_position(0.0,0.0);
    Cube_1.set_orientation(0.0,0.0,0.0,1.0);
    Cube_1.set_scale(1.0,1.0,1.0);
    Cube_1.set_colour(1.0,1.0,0.0);
    visualization_msgs::Marker marker2 = Cube_1;

    geometry_msgs::Point pointname;
    pointname.x = -1.0;
    pointname.y = -1.0;
    pointname.z = -1.0;

    //or
    Line_List LL_1;
    LL_1.set_point(pointname);
    LL_1.set_position(0.0,0.0);
    LL_1.set_orientation(0.0,0.0,0.0,1.0);
    LL_1.set_scale(0.1);
    LL_1.set_colour(1.0,1.0,0.0);
    //creating the line list's vertices
    LL_1.add_point(1.0,1.0,0.0);
    //pushing back the vertex add
    LL_1.add_point(2.0,2.0,0.0);
    LL_1.add_point(3.0,3.0,0.0);
    LL_1.sync_points();

    visualization_msgs::Marker marker3 = LL_1;

    //or
    Line_Strip LS_1;
    LS_1.set_position(0.0,0.0);
    LS_1.set_orientation(0.0,0.0,0.0,1.0);
    LS_1.set_scale(0.1);
    LS_1.set_colour(1.0,0.0,1.0);
    //creating the line list's vertices
    LS_1.add_point(-1.0,-1.0,0.0);
    //pushing back the vertex add
    LS_1.add_point(-2.0,-2.0,0.0);
    LS_1.add_point(-3.0,-3.0,0.0);
    LS_1.add_point(-5.0,-5.0,0.0);
    LS_1.add_point(-7.0,-7.0,0.0);
    LS_1.sync_points();
    visualization_msgs::Marker marker4 = LS_1;

    //or (can do the same for sphere, line list and line strip also)
    Cube Cube_2(0.0,0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0,1.0,0.0,1.0,0.0);
    visualization_msgs::Marker marker5 = Cube_2;

    //The SimplifiedMarkerMsg is a constructer of the parent class, we doubt you will use this ever but you can
    SimplifiedMarkerMsg marker_1;
    marker_1.set_type("SPHERE");
    marker_1.set_position(0.0,0.0);
    marker_1.set_orientation(0.0,0.0,0.0,1.0);
    marker_1.set_scale(1.0,1.0,1.0);
    marker_1.set_colour(1.0,0.0,0.0);
    ////THIS IS VERY IMPORTANT LINE
    visualization_msgs::Marker marker6 = marker_1;
    //Q. Is there a way to abstract this away too?

    //or
    SimplifiedMarkerMsg Spheremarker("SPHERE"); //you can change position/orientation/scale/colour using above methods
    visualization_msgs::Marker marker7 = Spheremarker;

    //or
    SimplifiedMarkerMsg Cubemarker("CUBE");//you can change position/orientation/scale/colour using above methods
    visualization_msgs::Marker marker8 = Cubemarker;

    //or
    SimplifiedMarkerMsg* LLmarker = new Line_List();//you can change position/orientation/scale/colour using above methods
    //creating the line list's vertices
    LLmarker->set_scale(0.1);
    LLmarker->add_point(1.0,1.0,0.0);
    LLmarker->set_colour(1.0,1.0,0.0);
    //pushing back the vertex add
    LLmarker->add_point(2.0,2.0,0.0);
    LLmarker->add_point(3.0,3.0,0.0);
    LLmarker->add_point(5.0,5.0,0.0);
    LLmarker->sync_points();
    visualization_msgs::Marker marker9 = *LLmarker;
    delete LLmarker;
    //or
    SimplifiedMarkerMsg* LSmarker = new Line_Strip();//you can change position/orientation/scale/colour using above methods
    //creating the line list's vertices
    LSmarker->set_scale(0.1);
    LSmarker->add_point(1.0,1.0,0.0);
    LSmarker->set_colour(0.0,0.0,1.0);
    //pushing back the vertex add
    LSmarker->add_point(2.0,2.0,0.0);
    LSmarker->add_point(3.0,3.0,0.0);
    LSmarker->add_point(5.0,5.0,0.0);
    LSmarker->sync_points();
    visualization_msgs::Marker marker10 = *LSmarker;
    delete LSmarker;
    // //or (can do the same for sphere, line list and line strip also)
    SimplifiedMarkerMsg ComplexCubemarker("CUBE",0.0,0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0,0.0);
    visualization_msgs::Marker marker11 = ComplexCubemarker;


    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please add a subscriber to the marker");
      sleep(1);
    }
  
    marker_pub.publish(marker1);
    system("sleep 5");

    marker_pub.publish(marker2);
    system("sleep 5");

    marker_pub.publish(marker3);
    system("sleep 5");

    marker_pub.publish(marker4);
    system("sleep 5");

    marker_pub.publish(marker5);
    system("sleep 5");

    marker_pub.publish(marker6);
    system("sleep 5");

    marker_pub.publish(marker7);
    system("sleep 5");

    marker_pub.publish(marker8);
    system("sleep 5");

    marker_pub.publish(marker9);
    system("sleep 5");

    marker_pub.publish(marker10);
    system("sleep 5");

    marker_pub.publish(marker11);
    system("sleep 5");

    r.sleep();
  }
}