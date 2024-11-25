// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/DisarmPixhawk.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__BUILDER_HPP_

#include "interfaces/srv/detail/disarm_pixhawk__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_DisarmPixhawk_Request_timeoutms
{
public:
  Init_DisarmPixhawk_Request_timeoutms()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::DisarmPixhawk_Request timeoutms(::interfaces::srv::DisarmPixhawk_Request::_timeoutms_type arg)
  {
    msg_.timeoutms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::DisarmPixhawk_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::DisarmPixhawk_Request>()
{
  return interfaces::srv::builder::Init_DisarmPixhawk_Request_timeoutms();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_DisarmPixhawk_Response_success
{
public:
  Init_DisarmPixhawk_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::DisarmPixhawk_Response success(::interfaces::srv::DisarmPixhawk_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::DisarmPixhawk_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::DisarmPixhawk_Response>()
{
  return interfaces::srv::builder::Init_DisarmPixhawk_Response_success();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__BUILDER_HPP_
