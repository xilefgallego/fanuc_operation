 /* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-diamondback-motion-planning-common-0.3.6/debian/ros-diamondback-motion-planning-common/opt/ros/diamondback/stacks/motion_planning_common/mapping_msgs/msg/CollisionObject.msg */
#ifndef MAPPING_MSGS_MESSAGE_COLLISIONOBJECT_H
#define MAPPING_MSGS_MESSAGE_COLLISIONOBJECT_H
#include <string>
#include <vector>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/message.h"
#include "ros/time.h"

#include "std_msgs/Header.h"
#include "/home/fgallego/dossier/src/urdf_tutorial/include/CollisionObjectOperation.h"
#include "/home/fgallego/dossier/src/urdf_tutorial/include/Shape.h"
#include "geometry_msgs/Pose.h"

namespace mapping_msgs
{
template <class ContainerAllocator>
struct CollisionObject_ : public ros::Message
{
  typedef CollisionObject_<ContainerAllocator> Type;

  CollisionObject_()
  : header()
  , id()
  , operation()
  , shapes()
  , poses()
  {
  }

  CollisionObject_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , id(_alloc)
  , operation(_alloc)
  , shapes(_alloc)
  , poses(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _id_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  id;

  typedef  ::mapping_msgs::CollisionObjectOperation_<ContainerAllocator>  _operation_type;
   ::mapping_msgs::CollisionObjectOperation_<ContainerAllocator>  operation;
 
  typedef std::vector< ::geometric_shapes_msgs::Shape_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometric_shapes_msgs::Shape_<ContainerAllocator> >::other >  _shapes_type;
  std::vector< ::geometric_shapes_msgs::Shape_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometric_shapes_msgs::Shape_<ContainerAllocator> >::other >  shapes;

  typedef std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other >  _poses_type;
  std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other >  poses;


  ROS_DEPRECATED uint32_t get_shapes_size() const { return (uint32_t)shapes.size(); }
  ROS_DEPRECATED void set_shapes_size(uint32_t size) { shapes.resize((size_t)size); }
  ROS_DEPRECATED void get_shapes_vec(std::vector< ::geometric_shapes_msgs::Shape_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometric_shapes_msgs::Shape_<ContainerAllocator> >::other > & vec) const { vec = this->shapes; }
  ROS_DEPRECATED void set_shapes_vec(const std::vector< ::geometric_shapes_msgs::Shape_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometric_shapes_msgs::Shape_<ContainerAllocator> >::other > & vec) { this->shapes = vec; }
  ROS_DEPRECATED uint32_t get_poses_size() const { return (uint32_t)poses.size(); }
  ROS_DEPRECATED void set_poses_size(uint32_t size) { poses.resize((size_t)size); }
  ROS_DEPRECATED void get_poses_vec(std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other > & vec) const { vec = this->poses; }
  ROS_DEPRECATED void set_poses_vec(const std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other > & vec) { this->poses = vec; }
private:
static const char* __s_getDataType_() { return "mapping_msgs/CollisionObject"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "c25d22faff81b340d88e28e270ae03f5"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# a header, used for interpreting the poses\n\
Header header\n\
\n\
# the id of the object\n\
string id\n\
\n\
#This contains what is to be done with the object\n\
CollisionObjectOperation operation\n\
\n\
#the shapes associated with the object\n\
geometric_shapes_msgs/Shape[] shapes\n\
\n\
#the poses associated with the shapes - will be transformed using the header\n\
geometry_msgs/Pose[] poses\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: mapping_msgs/CollisionObjectOperation\n\
#Puts the object into the environment\n\
#or updates the object if already added\n\
byte ADD=0\n\
\n\
#Removes the object from the environment entirely\n\
byte REMOVE=1\n\
\n\
#Only valid within the context of a CollisionAttachedObject message\n\
#Will be ignored if sent with an CollisionObject message\n\
#Takes an attached object, detaches from the attached link\n\
#But adds back in as regular object\n\
byte DETACH_AND_ADD_AS_OBJECT=2\n\
\n\
#Only valid within the context of a CollisionAttachedObject message\n\
#Will be ignored if sent with an CollisionObject message\n\
#Takes current object in the environment and removes it as\n\
#a regular object\n\
byte ATTACH_AND_REMOVE_AS_OBJECT=3\n\
\n\
# Byte code for operation\n\
byte operation\n\
\n\
================================================================================\n\
MSG: geometric_shapes_msgs/Shape\n\
byte SPHERE=0\n\
byte BOX=1\n\
byte CYLINDER=2\n\
byte MESH=3\n\
\n\
byte type\n\
\n\
\n\
#### define sphere, box, cylinder ####\n\
# the origin of each shape is considered at the shape's center\n\
\n\
# for sphere\n\
# radius := dimensions[0]\n\
\n\
# for cylinder\n\
# radius := dimensions[0]\n\
# length := dimensions[1]\n\
# the length is along the Z axis\n\
\n\
# for box\n\
# size_x := dimensions[0]\n\
# size_y := dimensions[1]\n\
# size_z := dimensions[2]\n\
float64[] dimensions\n\
\n\
\n\
#### define mesh ####\n\
\n\
# list of triangles; triangle k is defined by tre vertices located\n\
# at indices triangles[3k], triangles[3k+1], triangles[3k+2]\n\
int32[] triangles\n\
geometry_msgs/Point[] vertices\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, header);
    ros::serialization::serialize(stream, id);
    ros::serialization::serialize(stream, operation);
    ros::serialization::serialize(stream, shapes);
    ros::serialization::serialize(stream, poses);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, header);
    ros::serialization::deserialize(stream, id);
    ros::serialization::deserialize(stream, operation);
    ros::serialization::deserialize(stream, shapes);
    ros::serialization::deserialize(stream, poses);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(header);
    size += ros::serialization::serializationLength(id);
    size += ros::serialization::serializationLength(operation);
    size += ros::serialization::serializationLength(shapes);
    size += ros::serialization::serializationLength(poses);
    return size;
  }

  typedef boost::shared_ptr< ::mapping_msgs::CollisionObject_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mapping_msgs::CollisionObject_<ContainerAllocator>  const> ConstPtr;
}; // struct CollisionObject
typedef  ::mapping_msgs::CollisionObject_<std::allocator<void> > CollisionObject;

typedef boost::shared_ptr< ::mapping_msgs::CollisionObject> CollisionObjectPtr;
typedef boost::shared_ptr< ::mapping_msgs::CollisionObject const> CollisionObjectConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::mapping_msgs::CollisionObject_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::mapping_msgs::CollisionObject_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace mapping_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::mapping_msgs::CollisionObject_<ContainerAllocator> > {
  static const char* value() 
  {
    return "c25d22faff81b340d88e28e270ae03f5";
  }

  static const char* value(const  ::mapping_msgs::CollisionObject_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xc25d22faff81b340ULL;
  static const uint64_t static_value2 = 0xd88e28e270ae03f5ULL;
};

template<class ContainerAllocator>
struct DataType< ::mapping_msgs::CollisionObject_<ContainerAllocator> > {
  static const char* value() 
  {
    return "mapping_msgs/CollisionObject";
  }

  static const char* value(const  ::mapping_msgs::CollisionObject_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::mapping_msgs::CollisionObject_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# a header, used for interpreting the poses\n\
Header header\n\
\n\
# the id of the object\n\
string id\n\
\n\
#This contains what is to be done with the object\n\
CollisionObjectOperation operation\n\
\n\
#the shapes associated with the object\n\
geometric_shapes_msgs/Shape[] shapes\n\
\n\
#the poses associated with the shapes - will be transformed using the header\n\
geometry_msgs/Pose[] poses\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: mapping_msgs/CollisionObjectOperation\n\
#Puts the object into the environment\n\
#or updates the object if already added\n\
byte ADD=0\n\
\n\
#Removes the object from the environment entirely\n\
byte REMOVE=1\n\
\n\
#Only valid within the context of a CollisionAttachedObject message\n\
#Will be ignored if sent with an CollisionObject message\n\
#Takes an attached object, detaches from the attached link\n\
#But adds back in as regular object\n\
byte DETACH_AND_ADD_AS_OBJECT=2\n\
\n\
#Only valid within the context of a CollisionAttachedObject message\n\
#Will be ignored if sent with an CollisionObject message\n\
#Takes current object in the environment and removes it as\n\
#a regular object\n\
byte ATTACH_AND_REMOVE_AS_OBJECT=3\n\
\n\
# Byte code for operation\n\
byte operation\n\
\n\
================================================================================\n\
MSG: geometric_shapes_msgs/Shape\n\
byte SPHERE=0\n\
byte BOX=1\n\
byte CYLINDER=2\n\
byte MESH=3\n\
\n\
byte type\n\
\n\
\n\
#### define sphere, box, cylinder ####\n\
# the origin of each shape is considered at the shape's center\n\
\n\
# for sphere\n\
# radius := dimensions[0]\n\
\n\
# for cylinder\n\
# radius := dimensions[0]\n\
# length := dimensions[1]\n\
# the length is along the Z axis\n\
\n\
# for box\n\
# size_x := dimensions[0]\n\
# size_y := dimensions[1]\n\
# size_z := dimensions[2]\n\
float64[] dimensions\n\
\n\
\n\
#### define mesh ####\n\
\n\
# list of triangles; triangle k is defined by tre vertices located\n\
# at indices triangles[3k], triangles[3k+1], triangles[3k+2]\n\
int32[] triangles\n\
geometry_msgs/Point[] vertices\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
";
  }

  static const char* value(const  ::mapping_msgs::CollisionObject_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::mapping_msgs::CollisionObject_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::mapping_msgs::CollisionObject_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::mapping_msgs::CollisionObject_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.id);
    stream.next(m.operation);
    stream.next(m.shapes);
    stream.next(m.poses);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct CollisionObject_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mapping_msgs::CollisionObject_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::mapping_msgs::CollisionObject_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.id);
    s << indent << "operation: ";
s << std::endl;
    Printer< ::mapping_msgs::CollisionObjectOperation_<ContainerAllocator> >::stream(s, indent + "  ", v.operation);
    s << indent << "shapes[]" << std::endl;
    for (size_t i = 0; i < v.shapes.size(); ++i)
    {
      s << indent << "  shapes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometric_shapes_msgs::Shape_<ContainerAllocator> >::stream(s, indent + "    ", v.shapes[i]);
    }
    s << indent << "poses[]" << std::endl;
    for (size_t i = 0; i < v.poses.size(); ++i)
    {
      s << indent << "  poses[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "    ", v.poses[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // MAPPING_MSGS_MESSAGE_COLLISIONOBJECT_H


