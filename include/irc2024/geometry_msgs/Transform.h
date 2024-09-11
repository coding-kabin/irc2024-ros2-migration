// Generated by gencpp from file geometry_msgs/Transform.msg
// DO NOT EDIT!


#ifndef GEOMETRY_MSGS_MESSAGE_TRANSFORM_H
#define GEOMETRY_MSGS_MESSAGE_TRANSFORM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/msg/vector3.hpp>
#include <geometry_msgs/msg/quaternion.hpp>

namespace geometry_msgs
{
template <class ContainerAllocator>
struct Transform_
{
  typedef Transform_<ContainerAllocator> Type;

  Transform_()
    : translation()
    , rotation()  {
    }
  Transform_(const ContainerAllocator& _alloc)
    : translation(_alloc)
    , rotation(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::msg::Vector3_<ContainerAllocator>  _translation_type;
  _translation_type translation;

   typedef  ::geometry_msgs::msg::Quaternion_<ContainerAllocator>  _rotation_type;
  _rotation_type rotation;





  typedef std::shared_ptr< ::geometry_msgs::msg::Transform_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::geometry_msgs::msg::Transform_<ContainerAllocator> const> ConstPtr;

}; // struct Transform_

typedef ::geometry_msgs::msg::Transform_<std::allocator<void> > Transform;

typedef std::shared_ptr< ::geometry_msgs::msg::Transform > TransformPtr;
typedef std::shared_ptr< ::geometry_msgs::msg::Transform const> Transform::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geometry_msgs::msg::Transform_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geometry_msgs::msg::Transform_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::geometry_msgs::msg::Transform_<ContainerAllocator1> & lhs, const ::geometry_msgs::msg::Transform_<ContainerAllocator2> & rhs)
{
  return lhs.translation == rhs.translation &&
    lhs.rotation == rhs.rotation;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::geometry_msgs::msg::Transform_<ContainerAllocator1> & lhs, const ::geometry_msgs::msg::Transform_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace geometry_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::msg::Transform_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::msg::Transform_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::msg::Transform_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ac9eff44abf714214112b05d54a3cf9b";
  }

  static const char* value(const ::geometry_msgs::msg::Transform_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xac9eff44abf71421ULL;
  static const uint64_t static_value2 = 0x4112b05d54a3cf9bULL;
};

template<class ContainerAllocator>
struct DataType< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Transform";
  }

  static const char* value(const ::geometry_msgs::msg::Transform_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This represents the transform between two coordinate frames in free space.\n"
"\n"
"Vector3 translation\n"
"Quaternion rotation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::geometry_msgs::msg::Transform_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.translation);
      stream.next(m.rotation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Transform_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geometry_msgs::msg::Transform_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geometry_msgs::msg::Transform_<ContainerAllocator>& v)
  {
    s << indent << "translation: ";
    s << std::endl;
    Printer< ::geometry_msgs::msg::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.translation);
    s << indent << "rotation: ";
    s << std::endl;
    Printer< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.rotation);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GEOMETRY_MSGS_MESSAGE_TRANSFORM_H
