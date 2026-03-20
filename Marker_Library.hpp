#ifndef _MARKER_LIBRARY_H_
#define _MARKER_LIBRARY_H_

#include <iostream>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Point.h>
#include <vector>

/* ========================================================================
 *  Simplified Marker Message Library for ROS 
 *
 *  A lightweight C++ abstraction for RViz Marker creation and publishing. 
 * 
 *    AUTHORS: 
 *   - V.B. Dhanush         (Project Lead + Architect + C++ Programmer) 
 *   - Akshat Pathak        (C++ Programmer + Tester)
 *   - Praneeth Manickam    (C++, ROS Programmer )
 *   - Kareem               (C++ Programmer + Debugger)
 * ======================================================================== */

class SimplifiedMarkerMsg : public visualization_msgs::Marker {
protected:
    std::string shapetype;
    float position_x, position_y;
    float orientation_x, orientation_y, orientation_z, orientation_w;
    float scale_x, scale_y, scale_z;
    float colour_a, colour_r, colour_g, colour_b;
    float lifetime_sec;

public:
    SimplifiedMarkerMsg(const std::string& stype, float xp, float yp, float ox, float oy, float oz, float ow, float sx, float a, float r, float g, float b);
    SimplifiedMarkerMsg(const std::string& stype="SPHERE", float xp=0.0, float yp=0.0, float ox=0.0, float oy=0.0, float oz=0.0, float ow=1.0, float sx=1.0, float sy=1.0, float sz=1.0, float a=1.0, float r=1.0, float g=1.0, float b=1.0);
    void set_type(const std::string& stype);
    void set_position(float xp, float yp);
    void set_position(float xp, float yp, float ox, float oy, float oz, float ow);
    void set_orientation(float ox, float oy, float oz, float ow);
    void set_scale(float sx, float sy=0.0f, float sz=0.0f);
    void set_colour(float r, float g, float b);
    void set_lifetime(float seconds);
    void setDefaultColor(float r, float g, float b, float a);

    virtual void set_point(const geometry_msgs::Point& preset_point) {};
    virtual void add_point(float x, float y, float z) {};
    virtual void sync_points() {};
    virtual ~SimplifiedMarkerMsg() {}
};

class Cube : public SimplifiedMarkerMsg {
public:
    Cube();
    Cube(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float sy, float sz, float a, float r, float g, float b);
};

class Sphere : public SimplifiedMarkerMsg {
public:
    Sphere();
    Sphere(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float sy, float sz, float a, float r, float g, float b);
};

class Line_List : public SimplifiedMarkerMsg {
protected:
    std::vector<geometry_msgs::Point> points;
public:
    Line_List();
    Line_List(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float a, float r, float g, float b);
    void set_point(const geometry_msgs::Point& preset_point) override;
    void add_point(float x, float y, float z) override;
    void sync_points() override;
};

class Line_Strip : public SimplifiedMarkerMsg {
protected:
    std::vector<geometry_msgs::Point> points;
public:
    Line_Strip();
    Line_Strip(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float a, float r, float g, float b);
    void set_point(const geometry_msgs::Point& preset_point) override;
    void add_point(float x, float y, float z) override;
    void sync_points() override;
};

#endif