// Generated by gencpp from file sensor_msgs/Image.msg
// DO NOT EDIT!


#ifndef SENSOR_MSGS_MESSAGE_IMAGE_H
#define SENSOR_MSGS_MESSAGE_IMAGE_H


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
struct Image_
{
  typedef Image_<ContainerAllocator> Type;

  Image_()
    : header()
    , height(0)
    , width(0)
    , encoding()
    , is_bigendian(0)
    , step(0)
    , data()  {
    }
  Image_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , height(0)
    , width(0)
    , encoding(_alloc)
    , is_bigendian(0)
    , step(0)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::msg::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _height_type;
  _height_type height;

   typedef uint32_t _width_type;
  _width_type width;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _encoding_type;
  _encoding_type encoding;

   typedef uint8_t _is_bigendian_type;
  _is_bigendian_type is_bigendian;

   typedef uint32_t _step_type;
  _step_type step;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _data_type;
  _data_type data;





  typedef std::shared_ptr< ::sensor_msgs::msg::Image_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sensor_msgs::msg::Image_<ContainerAllocator> const> ConstPtr;

}; // struct Image_

typedef ::sensor_msgs::msg::Image_<std::allocator<void> > Image;

typedef std::shared_ptr< ::sensor_msgs::msg::Image > ImagePtr;
typedef std::shared_ptr< ::sensor_msgs::msg::Image const> Image::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sensor_msgs::msg::Image_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sensor_msgs::msg::Image_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sensor_msgs::msg::Image_<ContainerAllocator1> & lhs, const ::sensor_msgs::msg::Image_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.height == rhs.height &&
    lhs.width == rhs.width &&
    lhs.encoding == rhs.encoding &&
    lhs.is_bigendian == rhs.is_bigendian &&
    lhs.step == rhs.step &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sensor_msgs::msg::Image_<ContainerAllocator1> & lhs, const ::sensor_msgs::msg::Image_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sensor_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::msg::Image_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs::msg::Image_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::msg::Image_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs::msg::Image_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::msg::Image_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs::msg::Image_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sensor_msgs::msg::Image_<ContainerAllocator> >
{
  static const char* value()
  {
    return "060021388200f6f0f447d0fcd9c64743";
  }

  static const char* value(const ::sensor_msgs::msg::Image_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x060021388200f6f0ULL;
  static const uint64_t static_value2 = 0xf447d0fcd9c64743ULL;
};

template<class ContainerAllocator>
struct DataType< ::sensor_msgs::msg::Image_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/Image";
  }

  static const char* value(const ::sensor_msgs::msg::Image_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sensor_msgs::msg::Image_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This message contains an uncompressed image\n"
"# (0, 0) is at top-left corner of image\n"
"#\n"
"\n"
"Header header        # Header timestamp should be acquisition time of image\n"
"                     # Header frame_id should be optical frame of camera\n"
"                     # origin of frame should be optical center of camera\n"
"                     # +x should point to the right in the image\n"
"                     # +y should point down in the image\n"
"                     # +z should point into to plane of the image\n"
"                     # If the frame_id here and the frame_id of the CameraInfo\n"
"                     # message associated with the image conflict\n"
"                     # the behavior is undefined\n"
"\n"
"uint32 height         # image height, that is, number of rows\n"
"uint32 width          # image width, that is, number of columns\n"
"\n"
"# The legal values for encoding are in file src/image_encodings.cpp\n"
"# If you want to standardize a new string format, join\n"
"# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n"
"\n"
"string encoding       # Encoding of pixels -- channel meaning, ordering, size\n"
"                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n"
"\n"
"uint8 is_bigendian    # is this data bigendian?\n"
"uint32 step           # Full row length in bytes\n"
"uint8[] data          # actual matrix data, size is (step * rows)\n"
"\n"
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

  static const char* value(const ::sensor_msgs::msg::Image_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sensor_msgs::msg::Image_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.height);
      stream.next(m.width);
      stream.next(m.encoding);
      stream.next(m.is_bigendian);
      stream.next(m.step);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Image_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sensor_msgs::msg::Image_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sensor_msgs::msg::Image_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::msg::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "height: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.height);
    s << indent << "width: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.width);
    s << indent << "encoding: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.encoding);
    s << indent << "is_bigendian: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_bigendian);
    s << indent << "step: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.step);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_MSGS_MESSAGE_IMAGE_H
