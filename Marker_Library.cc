#include "Marker_Library.hpp"

/* ========================================================================
 *  Simplified Marker Message Library for ROS 
 *
 *  A lightweight C++ abstraction for RViz Marker creation and publishing. 
 * 
 *    AUTHORS: 
 *   - V.B. Dhanush         (Project Lead + Architect + C++ Programmer) 
 *   - Akshat Pathak        (C++ Programmer + Tester)
 *   - Praneeth Manickam    (C++,ROS Programmer )
 *   - Kareem               (C++ Programmer + Debugger)
 * ======================================================================== */

//without sy, sz
SimplifiedMarkerMsg::SimplifiedMarkerMsg(const std::string& stype, float xp, float yp, float ox, float oy, float oz, float ow, float sx, float a, float r, float g, float b)
:SimplifiedMarkerMsg(stype, xp, yp, ox, oy, oz, ow, sx, sx ,sx, a, r, g, b){}

//super constructor
SimplifiedMarkerMsg::SimplifiedMarkerMsg(const std::string& stype, float xp, float yp, float ox, float oy, float oz, float ow, float sx, float sy, float sz, float a, float r, float g, float b)
: shapetype(stype), position_x(xp), position_y(yp), orientation_x(ox), orientation_y(oy), orientation_z(oz), orientation_w(ow), scale_x(sx), scale_y(sy), scale_z(sz), colour_a(a), colour_r(r), colour_g(g), colour_b(b), lifetime_sec(1.0) {
    header.frame_id = "base_link";
    header.stamp = ros::Time::now();
    ns = "my_namespace";
    id = 0;
    action = visualization_msgs::Marker::ADD;
    set_type(shapetype);
    set_position(xp, yp);
    set_orientation(ox, oy, oz, ow);
    set_scale(sx, sy, sz);
    set_colour(r, g, b);
    lifetime = ros::Duration(lifetime_sec);
}

void SimplifiedMarkerMsg::set_type(const std::string& stype) {
    if (stype == "SPHERE") type = visualization_msgs::Marker::SPHERE;
    else if (stype == "CUBE") type = visualization_msgs::Marker::CUBE;
    else if (stype == "LINE_LIST") type = visualization_msgs::Marker::LINE_LIST;
    else if (stype == "LINE_STRIP") type = visualization_msgs::Marker::LINE_STRIP;
    else ROS_WARN("Unknown marker type: %s", stype.c_str());
}

void SimplifiedMarkerMsg::set_position(float xp, float yp) {

    pose.position.x = xp;
    pose.position.y = yp;
    pose.position.z = 0.0;
}

void SimplifiedMarkerMsg::set_position(float xp, float yp, float ox, float oy, float oz, float ow) {
    set_position(xp, yp);
    set_orientation(ox, oy, oz, ow);
}

void SimplifiedMarkerMsg::set_orientation(float ox, float oy, float oz, float ow) {
    pose.orientation.x = ox;
    pose.orientation.y = oy;
    pose.orientation.z = oz;
    pose.orientation.w = ow;
}


void SimplifiedMarkerMsg::set_scale(float sx, float sy, float sz) {
    scale.x = sx;
    scale.y = sy;
    scale.z = sz;
}

void SimplifiedMarkerMsg::set_colour(float r, float g, float b) {
    if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1) {
        ROS_WARN("Color values must be in range [0.0, 1.0]");
        return;
    }
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = colour_a;
}

void SimplifiedMarkerMsg::set_lifetime(float seconds) {
    lifetime_sec = seconds;
    lifetime = ros::Duration(seconds);
}

void SimplifiedMarkerMsg::setDefaultColor(float r, float g, float b, float a) {
    if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1 || a < 0 || a > 1) {
        ROS_WARN("Default color components must be in range [0.0, 1.0]");
        return;
    }
    colour_r = r;
    colour_g = g;
    colour_b = b;
    colour_a = a;
}

Cube::Cube() : SimplifiedMarkerMsg("CUBE") {}
Cube::Cube(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float sy, float sz, float a, float r, float g, float b)
: SimplifiedMarkerMsg("CUBE", xp, yp, ox, oy, oz, ow, sx, sy, sz, a, r, g, b) {}

Sphere::Sphere() : SimplifiedMarkerMsg("SPHERE") {}
Sphere::Sphere(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float sy, float sz, float a, float r, float g, float b)
: SimplifiedMarkerMsg("SPHERE", xp, yp, ox, oy, oz, ow, sx, sy, sz, a, r, g, b) {}

Line_List::Line_List() : SimplifiedMarkerMsg("LINE_LIST") {}
Line_List::Line_List(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float a, float r, float g, float b)
: SimplifiedMarkerMsg("LINE_LIST", xp, yp, ox, oy, oz, ow, sx, 0.0, 0.0, a, r, g, b) {}

Line_Strip::Line_Strip() : SimplifiedMarkerMsg("LINE_STRIP") {}
Line_Strip::Line_Strip(float xp, float yp, float ox, float oy, float oz, float ow, float sx, float a, float r, float g, float b)
: SimplifiedMarkerMsg("LINE_STRIP", xp, yp, ox, oy, oz, ow, sx, 0.0, 0.0, a, r, g, b) {}

void Line_List::set_point(const geometry_msgs::Point& preset_point) {
    points.push_back(preset_point);
}

void Line_List::add_point(float x, float y, float z) {
    geometry_msgs::Point p;
    p.x = x; p.y = y; p.z = z;
    points.push_back(p);
}

void Line_List::sync_points() {
    this->visualization_msgs::Marker::points = this->points;
}

void Line_Strip::set_point(const geometry_msgs::Point& preset_point) {
    points.push_back(preset_point);
}

void Line_Strip::add_point(float x, float y, float z) {
    geometry_msgs::Point p;
    p.x = x; p.y = y; p.z = z;
    points.push_back(p);
}

void Line_Strip::sync_points() {
    this->visualization_msgs::Marker::points = this->points;
}   