// Generated by gencpp from file nav_msgs/SetMap.msg
// DO NOT EDIT!


#ifndef NAV_MSGS_MESSAGE_SETMAP_H
#define NAV_MSGS_MESSAGE_SETMAP_H

#include <ros/service_traits.h>


#include <nav_msgs/SetMapRequest.h>
#include <nav_msgs/SetMapResponse.h>


namespace nav_msgs
{

struct SetMap
{

typedef SetMapRequest Request;
typedef SetMapResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetMap
} // namespace nav_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::nav_msgs::srv::SetMap > {
  static const char* value()
  {
    return "c36922319011e63ed7784112ad4fdd32";
  }

  static const char* value(const ::nav_msgs::srv::SetMap&) { return value(); }
};

template<>
struct DataType< ::nav_msgs::srv::SetMap > {
  static const char* value()
  {
    return "nav_msgs/SetMap";
  }

  static const char* value(const ::nav_msgs::srv::SetMap&) { return value(); }
};


// service_traits::MD5Sum< ::nav_msgs::srv::SetMapRequest> should match
// service_traits::MD5Sum< ::nav_msgs::srv::SetMap >
template<>
struct MD5Sum< ::nav_msgs::srv::SetMapRequest>
{
  static const char* value()
  {
    return MD5Sum< ::nav_msgs::srv::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::SetMapRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::nav_msgs::srv::SetMapRequest> should match
// service_traits::DataType< ::nav_msgs::srv::SetMap >
template<>
struct DataType< ::nav_msgs::srv::SetMapRequest>
{
  static const char* value()
  {
    return DataType< ::nav_msgs::srv::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::SetMapRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::nav_msgs::srv::SetMapResponse> should match
// service_traits::MD5Sum< ::nav_msgs::srv::SetMap >
template<>
struct MD5Sum< ::nav_msgs::srv::SetMapResponse>
{
  static const char* value()
  {
    return MD5Sum< ::nav_msgs::srv::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::SetMapResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::nav_msgs::srv::SetMapResponse> should match
// service_traits::DataType< ::nav_msgs::srv::SetMap >
template<>
struct DataType< ::nav_msgs::srv::SetMapResponse>
{
  static const char* value()
  {
    return DataType< ::nav_msgs::srv::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::SetMapResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NAV_MSGS_MESSAGE_SETMAP_H