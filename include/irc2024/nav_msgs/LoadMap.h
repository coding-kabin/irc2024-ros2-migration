// Generated by gencpp from file nav_msgs/LoadMap.msg
// DO NOT EDIT!


#ifndef NAV_MSGS_MESSAGE_LOADMAP_H
#define NAV_MSGS_MESSAGE_LOADMAP_H

#include <ros/service_traits.h>


#include <nav_msgs/LoadMapRequest.h>
#include <nav_msgs/LoadMapResponse.h>


namespace nav_msgs
{

struct LoadMap
{

typedef LoadMapRequest Request;
typedef LoadMapResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct LoadMap
} // namespace nav_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::nav_msgs::srv::LoadMap > {
  static const char* value()
  {
    return "22e647fdfbe3b23c8c9f419908afaebd";
  }

  static const char* value(const ::nav_msgs::srv::LoadMap&) { return value(); }
};

template<>
struct DataType< ::nav_msgs::srv::LoadMap > {
  static const char* value()
  {
    return "nav_msgs/LoadMap";
  }

  static const char* value(const ::nav_msgs::srv::LoadMap&) { return value(); }
};


// service_traits::MD5Sum< ::nav_msgs::srv::LoadMapRequest> should match
// service_traits::MD5Sum< ::nav_msgs::srv::LoadMap >
template<>
struct MD5Sum< ::nav_msgs::srv::LoadMapRequest>
{
  static const char* value()
  {
    return MD5Sum< ::nav_msgs::srv::LoadMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::LoadMapRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::nav_msgs::srv::LoadMapRequest> should match
// service_traits::DataType< ::nav_msgs::srv::LoadMap >
template<>
struct DataType< ::nav_msgs::srv::LoadMapRequest>
{
  static const char* value()
  {
    return DataType< ::nav_msgs::srv::LoadMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::LoadMapRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::nav_msgs::srv::LoadMapResponse> should match
// service_traits::MD5Sum< ::nav_msgs::srv::LoadMap >
template<>
struct MD5Sum< ::nav_msgs::srv::LoadMapResponse>
{
  static const char* value()
  {
    return MD5Sum< ::nav_msgs::srv::LoadMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::LoadMapResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::nav_msgs::srv::LoadMapResponse> should match
// service_traits::DataType< ::nav_msgs::srv::LoadMap >
template<>
struct DataType< ::nav_msgs::srv::LoadMapResponse>
{
  static const char* value()
  {
    return DataType< ::nav_msgs::srv::LoadMap >::value();
  }
  static const char* value(const ::nav_msgs::srv::LoadMapResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NAV_MSGS_MESSAGE_LOADMAP_H
