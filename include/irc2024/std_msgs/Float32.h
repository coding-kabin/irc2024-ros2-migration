// Generated by gencpp from file std_msgs/Float32.msg
// DO NOT EDIT!


#ifndef STD_MSGS_MESSAGE_FLOAT32_H
#define STD_MSGS_MESSAGE_FLOAT32_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace std_msgs
{
template <class ContainerAllocator>
struct Float32_
{
  typedef Float32_<ContainerAllocator> Type;

  Float32_()
    : data(0.0)  {
    }
  Float32_(const ContainerAllocator& _alloc)
    : data(0.0)  {
  (void)_alloc;
    }



   typedef float _data_type;
  _data_type data;





  typedef std::shared_ptr< ::std_msgs::msg::Float32_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::std_msgs::msg::Float32_<ContainerAllocator> const> ConstPtr;

}; // struct Float32_

typedef ::std_msgs::msg::Float32_<std::allocator<void> > Float32;

typedef std::shared_ptr< ::std_msgs::msg::Float32 > Float32Ptr;
typedef std::shared_ptr< ::std_msgs::msg::Float32 const> Float32::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::std_msgs::msg::Float32_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::std_msgs::msg::Float32_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::std_msgs::msg::Float32_<ContainerAllocator1> & lhs, const ::std_msgs::msg::Float32_<ContainerAllocator2> & rhs)
{
  return lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::std_msgs::msg::Float32_<ContainerAllocator1> & lhs, const ::std_msgs::msg::Float32_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace std_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::std_msgs::msg::Float32_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::std_msgs::msg::Float32_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::std_msgs::msg::Float32_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::std_msgs::msg::Float32_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::std_msgs::msg::Float32_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::std_msgs::msg::Float32_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::std_msgs::msg::Float32_<ContainerAllocator> >
{
  static const char* value()
  {
    return "73fcbf46b49191e672908e50842a83d4";
  }

  static const char* value(const ::std_msgs::msg::Float32_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x73fcbf46b49191e6ULL;
  static const uint64_t static_value2 = 0x72908e50842a83d4ULL;
};

template<class ContainerAllocator>
struct DataType< ::std_msgs::msg::Float32_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Float32";
  }

  static const char* value(const ::std_msgs::msg::Float32_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::std_msgs::msg::Float32_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 data\n"
;
  }

  static const char* value(const ::std_msgs::msg::Float32_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::std_msgs::msg::Float32_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Float32_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::std_msgs::msg::Float32_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::std_msgs::msg::Float32_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    Printer<float>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // STD_MSGS_MESSAGE_FLOAT32_H
