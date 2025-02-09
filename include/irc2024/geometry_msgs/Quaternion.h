// Generated by gencpp from file geometry_msgs/Quaternion.msg
// DO NOT EDIT!


#ifndef GEOMETRY_MSGS_MESSAGE_QUATERNION_H
#define GEOMETRY_MSGS_MESSAGE_QUATERNION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace geometry_msgs
{
template <class ContainerAllocator>
struct Quaternion_
{
  typedef Quaternion_<ContainerAllocator> Type;

  Quaternion_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , w(0.0)  {
    }
  Quaternion_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , w(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _w_type;
  _w_type w;





  typedef std::shared_ptr< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> const> ConstPtr;

}; // struct Quaternion_

typedef ::geometry_msgs::msg::Quaternion_<std::allocator<void> > Quaternion;

typedef std::shared_ptr< ::geometry_msgs::msg::Quaternion > QuaternionPtr;
typedef std::shared_ptr< ::geometry_msgs::msg::Quaternion const> Quaternion::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geometry_msgs::msg::Quaternion_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::geometry_msgs::msg::Quaternion_<ContainerAllocator1> & lhs, const ::geometry_msgs::msg::Quaternion_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.w == rhs.w;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::geometry_msgs::msg::Quaternion_<ContainerAllocator1> & lhs, const ::geometry_msgs::msg::Quaternion_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace geometry_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a779879fadf0160734f906b8c19c7004";
  }

  static const char* value(const ::geometry_msgs::msg::Quaternion_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa779879fadf01607ULL;
  static const uint64_t static_value2 = 0x34f906b8c19c7004ULL;
};

template<class ContainerAllocator>
struct DataType< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Quaternion";
  }

  static const char* value(const ::geometry_msgs::msg::Quaternion_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::geometry_msgs::msg::Quaternion_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.w);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Quaternion_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geometry_msgs::msg::Quaternion_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geometry_msgs::msg::Quaternion_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "w: ";
    Printer<double>::stream(s, indent + "  ", v.w);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GEOMETRY_MSGS_MESSAGE_QUATERNION_H
