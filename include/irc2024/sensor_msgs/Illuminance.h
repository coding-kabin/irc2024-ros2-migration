// Generated by gencpp from file sensor_msgs/Illuminance.msg
// DO NOT EDIT!


#ifndef SENSOR_MSGS_MESSAGE_ILLUMINANCE_H
#define SENSOR_MSGS_MESSAGE_ILLUMINANCE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/msg/header.hpp>

namespace sensor_msgs
{
template <class ContainerAllocator>
struct Illuminance_
{
  typedef Illuminance_<ContainerAllocator> Type;

  Illuminance_()
    : header()
    , illuminance(0.0)
    , variance(0.0)  {
    }
  Illuminance_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , illuminance(0.0)
    , variance(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::msg::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _illuminance_type;
  _illuminance_type illuminance;

   typedef double _variance_type;
  _variance_type variance;





  typedef std::shared_ptr< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> const> ConstPtr;

}; // struct Illuminance_

typedef ::sensor_msgs::msg::Illuminance_<std::allocator<void> > Illuminance;

typedef std::shared_ptr< ::sensor_msgs::msg::Illuminance > IlluminancePtr;
typedef std::shared_ptr< ::sensor_msgs::msg::Illuminance const> Illuminance::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sensor_msgs::msg::Illuminance_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sensor_msgs::msg::Illuminance_<ContainerAllocator1> & lhs, const ::sensor_msgs::msg::Illuminance_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.illuminance == rhs.illuminance &&
    lhs.variance == rhs.variance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sensor_msgs::msg::Illuminance_<ContainerAllocator1> & lhs, const ::sensor_msgs::msg::Illuminance_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sensor_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8cf5febb0952fca9d650c3d11a81a188";
  }

  static const char* value(const ::sensor_msgs::msg::Illuminance_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8cf5febb0952fca9ULL;
  static const uint64_t static_value2 = 0xd650c3d11a81a188ULL;
};

template<class ContainerAllocator>
struct DataType< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/Illuminance";
  }

  static const char* value(const ::sensor_msgs::msg::Illuminance_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
{
  static const char* value()
  {
    return " # Single photometric illuminance measurement.  Light should be assumed to be\n"
" # measured along the sensor's x-axis (the area of detection is the y-z plane).\n"
" # The illuminance should have a 0 or positive value and be received with\n"
" # the sensor's +X axis pointing toward the light source.\n"
"\n"
" # Photometric illuminance is the measure of the human eye's sensitivity of the\n"
" # intensity of light encountering or passing through a surface.\n"
"\n"
" # All other Photometric and Radiometric measurements should\n"
" # not use this message.\n"
" # This message cannot represent:\n"
" # Luminous intensity (candela/light source output)\n"
" # Luminance (nits/light output per area)\n"
" # Irradiance (watt/area), etc.\n"
"\n"
" Header header           # timestamp is the time the illuminance was measured\n"
"                         # frame_id is the location and direction of the reading\n"
"\n"
" float64 illuminance     # Measurement of the Photometric Illuminance in Lux.\n"
"\n"
" float64 variance        # 0 is interpreted as variance unknown\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::sensor_msgs::msg::Illuminance_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.illuminance);
      stream.next(m.variance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Illuminance_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sensor_msgs::msg::Illuminance_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sensor_msgs::msg::Illuminance_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::msg::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "illuminance: ";
    Printer<double>::stream(s, indent + "  ", v.illuminance);
    s << indent << "variance: ";
    Printer<double>::stream(s, indent + "  ", v.variance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_MSGS_MESSAGE_ILLUMINANCE_H
