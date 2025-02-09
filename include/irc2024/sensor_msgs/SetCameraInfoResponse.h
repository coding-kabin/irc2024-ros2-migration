// Generated by gencpp from file sensor_msgs/SetCameraInfoResponse.msg
// DO NOT EDIT!


#ifndef SENSOR_MSGS_MESSAGE_SETCAMERAINFORESPONSE_H
#define SENSOR_MSGS_MESSAGE_SETCAMERAINFORESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sensor_msgs
{
template <class ContainerAllocator>
struct SetCameraInfoResponse_
{
  typedef SetCameraInfoResponse_<ContainerAllocator> Type;

  SetCameraInfoResponse_()
    : success(false)
    , status_message()  {
    }
  SetCameraInfoResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , status_message(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_message_type;
  _status_message_type status_message;





  typedef std::shared_ptr< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetCameraInfoResponse_

typedef ::sensor_msgs::srv::SetCameraInfoResponse_<std::allocator<void> > SetCameraInfoResponse;

typedef std::shared_ptr< ::sensor_msgs::srv::SetCameraInfoResponse > SetCameraInfoResponsePtr;
typedef std::shared_ptr< ::sensor_msgs::srv::SetCameraInfoResponse const> SetCameraInfoResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator1> & lhs, const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success &&
    lhs.status_message == rhs.status_message;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator1> & lhs, const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sensor_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ec6f3eff0161f4257b808b12bc830c2";
  }

  static const char* value(const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ec6f3eff0161f42ULL;
  static const uint64_t static_value2 = 0x57b808b12bc830c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/SetCameraInfoResponse";
  }

  static const char* value(const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success          # True if the call succeeded\n"
"string status_message # Used to give details about success\n"
"\n"
;
  }

  static const char* value(const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.status_message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetCameraInfoResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sensor_msgs::srv::SetCameraInfoResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "status_message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status_message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_MSGS_MESSAGE_SETCAMERAINFORESPONSE_H
