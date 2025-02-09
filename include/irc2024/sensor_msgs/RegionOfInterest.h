// Generated by gencpp from file sensor_msgs/RegionOfInterest.msg
// DO NOT EDIT!


#ifndef SENSOR_MSGS_MESSAGE_REGIONOFINTEREST_H
#define SENSOR_MSGS_MESSAGE_REGIONOFINTEREST_H


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
struct RegionOfInterest_
{
  typedef RegionOfInterest_<ContainerAllocator> Type;

  RegionOfInterest_()
    : x_offset(0)
    , y_offset(0)
    , height(0)
    , width(0)
    , do_rectify(false)  {
    }
  RegionOfInterest_(const ContainerAllocator& _alloc)
    : x_offset(0)
    , y_offset(0)
    , height(0)
    , width(0)
    , do_rectify(false)  {
  (void)_alloc;
    }



   typedef uint32_t _x_offset_type;
  _x_offset_type x_offset;

   typedef uint32_t _y_offset_type;
  _y_offset_type y_offset;

   typedef uint32_t _height_type;
  _height_type height;

   typedef uint32_t _width_type;
  _width_type width;

   typedef uint8_t _do_rectify_type;
  _do_rectify_type do_rectify;





  typedef std::shared_ptr< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> const> ConstPtr;

}; // struct RegionOfInterest_

typedef ::sensor_msgs::msg::RegionOfInterest_<std::allocator<void> > RegionOfInterest;

typedef std::shared_ptr< ::sensor_msgs::msg::RegionOfInterest > RegionOfInterestPtr;
typedef std::shared_ptr< ::sensor_msgs::msg::RegionOfInterest const> RegionOfInterest::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator1> & lhs, const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator2> & rhs)
{
  return lhs.x_offset == rhs.x_offset &&
    lhs.y_offset == rhs.y_offset &&
    lhs.height == rhs.height &&
    lhs.width == rhs.width &&
    lhs.do_rectify == rhs.do_rectify;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator1> & lhs, const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sensor_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bdb633039d588fcccb441a4d43ccfe09";
  }

  static const char* value(const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbdb633039d588fccULL;
  static const uint64_t static_value2 = 0xcb441a4d43ccfe09ULL;
};

template<class ContainerAllocator>
struct DataType< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/RegionOfInterest";
  }

  static const char* value(const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This message is used to specify a region of interest within an image.\n"
"#\n"
"# When used to specify the ROI setting of the camera when the image was\n"
"# taken, the height and width fields should either match the height and\n"
"# width fields for the associated image; or height = width = 0\n"
"# indicates that the full resolution image was captured.\n"
"\n"
"uint32 x_offset  # Leftmost pixel of the ROI\n"
"                 # (0 if the ROI includes the left edge of the image)\n"
"uint32 y_offset  # Topmost pixel of the ROI\n"
"                 # (0 if the ROI includes the top edge of the image)\n"
"uint32 height    # Height of ROI\n"
"uint32 width     # Width of ROI\n"
"\n"
"# True if a distinct rectified ROI should be calculated from the \"raw\"\n"
"# ROI in this message. Typically this should be False if the full image\n"
"# is captured (ROI not used), and True if a subwindow is captured (ROI\n"
"# used).\n"
"bool do_rectify\n"
;
  }

  static const char* value(const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x_offset);
      stream.next(m.y_offset);
      stream.next(m.height);
      stream.next(m.width);
      stream.next(m.do_rectify);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RegionOfInterest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>& v)
  {
    s << indent << "x_offset: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.x_offset);
    s << indent << "y_offset: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.y_offset);
    s << indent << "height: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.height);
    s << indent << "width: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.width);
    s << indent << "do_rectify: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.do_rectify);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_MSGS_MESSAGE_REGIONOFINTEREST_H
