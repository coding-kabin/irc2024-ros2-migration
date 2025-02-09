// Generated by gencpp from file std_msgs/Int8MultiArray.msg
// DO NOT EDIT!


#ifndef STD_MSGS_MESSAGE_INT8MULTIARRAY_H
#define STD_MSGS_MESSAGE_INT8MULTIARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/msg/multi_array_layout.hpp>

namespace std_msgs
{
template <class ContainerAllocator>
struct Int8MultiArray_
{
  typedef Int8MultiArray_<ContainerAllocator> Type;

  Int8MultiArray_()
    : layout()
    , data()  {
    }
  Int8MultiArray_(const ContainerAllocator& _alloc)
    : layout(_alloc)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::msg::MultiArrayLayout_<ContainerAllocator>  _layout_type;
  _layout_type layout;

   typedef std::vector<int8_t, typename ContainerAllocator::template rebind<int8_t>::other >  _data_type;
  _data_type data;





  typedef std::shared_ptr< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> const> ConstPtr;

}; // struct Int8MultiArray_

typedef ::std_msgs::msg::Int8MultiArray_<std::allocator<void> > Int8MultiArray;

typedef std::shared_ptr< ::std_msgs::msg::Int8MultiArray > Int8MultiArrayPtr;
typedef std::shared_ptr< ::std_msgs::msg::Int8MultiArray const> Int8MultiArray::ConstSharedPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator1> & lhs, const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator2> & rhs)
{
  return lhs.layout == rhs.layout &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator1> & lhs, const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace std_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d7c1af35a1b4781bbe79e03dd94b7c13";
  }

  static const char* value(const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd7c1af35a1b4781bULL;
  static const uint64_t static_value2 = 0xbe79e03dd94b7c13ULL;
};

template<class ContainerAllocator>
struct DataType< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Int8MultiArray";
  }

  static const char* value(const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Please look at the MultiArrayLayout message definition for\n"
"# documentation on all multiarrays.\n"
"\n"
"MultiArrayLayout  layout        # specification of data layout\n"
"int8[]            data          # array of data\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayLayout\n"
"# The multiarray declares a generic multi-dimensional array of a\n"
"# particular data type.  Dimensions are ordered from outer most\n"
"# to inner most.\n"
"\n"
"MultiArrayDimension[] dim # Array of dimension properties\n"
"uint32 data_offset        # padding elements at front of data\n"
"\n"
"# Accessors should ALWAYS be written in terms of dimension stride\n"
"# and specified outer-most dimension first.\n"
"# \n"
"# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]\n"
"#\n"
"# A standard, 3-channel 640x480 image with interleaved color channels\n"
"# would be specified as:\n"
"#\n"
"# dim[0].label  = \"height\"\n"
"# dim[0].size   = 480\n"
"# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)\n"
"# dim[1].label  = \"width\"\n"
"# dim[1].size   = 640\n"
"# dim[1].stride = 3*640 = 1920\n"
"# dim[2].label  = \"channel\"\n"
"# dim[2].size   = 3\n"
"# dim[2].stride = 3\n"
"#\n"
"# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayDimension\n"
"string label   # label of given dimension\n"
"uint32 size    # size of given dimension (in type units)\n"
"uint32 stride  # stride of given dimension\n"
;
  }

  static const char* value(const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.layout);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Int8MultiArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::std_msgs::msg::Int8MultiArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::std_msgs::msg::Int8MultiArray_<ContainerAllocator>& v)
  {
    s << indent << "layout: ";
    s << std::endl;
    Printer< ::std_msgs::msg::MultiArrayLayout_<ContainerAllocator> >::stream(s, indent + "  ", v.layout);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<int8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // STD_MSGS_MESSAGE_INT8MULTIARRAY_H
