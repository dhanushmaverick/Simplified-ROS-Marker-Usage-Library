Note: This repository is a curated version created to showcase the final implementation and key outcomes of the project. It does not contain the complete original commit history from the development phase. 

AUTHORS:
1. V.B.Dhanush [Project Lead]
2. Praneeth Manickam 
3. Akshat Pathak
4. Kareem 

🛠️ Setup
cd ~/catkin_ws
catkin_make
source devel/setup.bash
rosrun your_package ros_ws

--------------------------------------------------------------------
Welcome to the C++ Library for Simplified Marker Messages
Here are the relevant files:
1. Marker_Library.hpp -> The header file for our Library
2. Marker_Library.cpp -> The source code file for our Library
3. ros_ws.cpp -> Test Code with 10 tests demonstrating how to use this Library for messages
4. CMakeLists.txt -> ROS CMakeLists dependency for smooth and quick execution
5. package.xml -> ROS package dependency 

With this library you can create the following marker objects much easier
1. CUBE
2. SPHERE
3. LINE_LIST
4. LINE_STRIP

Example Functionality:

🚀 Usage Example
Line_List line_marker(0, 0, 0, 0, 0, 1, 0.05, 1.0, 1.0, 0.0, 0.0);  // red line
line_marker.add_point(0, 0, 0);
line_marker.add_point(1, 1, 0);
line_marker.sync_points();

📌 Customization
Each marker has functions like:

set_position(x, y, ox, oy, oz, ow);
set_scale(sx, sy, sz);
set_colour(r, g, b);
set_lifetime(seconds);

Line_List and Line_Strip support:

add_point(x, y, z);
set_point(geometry_msgs::Point);
sync_points();  // syncs internal points to the marker

Constructor Types:

🧱 SimplifiedMarkerMsg Constructors (Base Class)
1. With custom scale in all 3 axes

SimplifiedMarkerMsg(const std::string& stype = "SPHERE",
                    float xp = 0.0, float yp = 0.0,
                    float ox = 0.0, float oy = 0.0, float oz = 0.0, float ow = 1.0,
                    float sx = 1.0, float sy = 1.0, float sz = 1.0,
                    float a = 1.0, float r = 1.0, float g = 1.0, float b = 1.0);
2. Uniform scale constructor (scale = sx in all 3 axes)

SimplifiedMarkerMsg(const std::string& stype,
                    float xp, float yp,
                    float ox, float oy, float oz, float ow,
                    float sx,
                    float a, float r, float g, float b);
🔍 Parameter meanings
Parameter	Description
stype	Shape type: "SPHERE", "CUBE", "LINE_LIST", "LINE_STRIP"
xp, yp	Position in X and Y (Z is 0 by default)
ox, oy, oz, ow	Quaternion orientation for 3D rotation
sx, sy, sz	Scale along X, Y, Z axes (size or thickness)
a, r, g, b	Alpha (transparency), Red, Green, Blue color values

⚪ Sphere Constructors
Sphere();  // Default sphere at origin with default color and scale

Sphere(float xp, float yp,
       float ox, float oy, float oz, float ow,
       float sx, float sy, float sz,
       float a, float r, float g, float b);
Just wraps the SimplifiedMarkerMsg constructor with "SPHERE" type.

🟥 Cube Constructors
Cube();  // Default cube at origin

Cube(float xp, float yp,
     float ox, float oy, float oz, float ow,
     float sx, float sy, float sz,
     float a, float r, float g, float b);
Wraps the base class constructor with "CUBE" type.

📏 Line_List Constructors

Line_List();  // Default empty line list

Line_List(float xp, float yp,
          float ox, float oy, float oz, float ow,
          float sx, float a,
          float r, float g, float b);
Used for drawing non-connected segments between point pairs.

sx sets line width.

Z is 0 by default for position.

📈 Line_Strip Constructors

Line_Strip();  // Default empty line strip

Line_Strip(float xp, float yp,
           float ox, float oy, float oz, float ow,
           float sx, float a,
           float r, float g, float b);
Used for drawing a connected path of points.

Same params as Line_List.
