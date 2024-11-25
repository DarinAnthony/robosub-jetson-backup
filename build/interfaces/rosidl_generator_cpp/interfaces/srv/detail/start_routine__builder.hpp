// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/StartRoutine.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__START_ROUTINE__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__START_ROUTINE__BUILDER_HPP_

#include "interfaces/srv/detail/start_routine__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_StartRoutine_Request_start
{
public:
  Init_StartRoutine_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::StartRoutine_Request start(::interfaces::srv::StartRoutine_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::StartRoutine_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::StartRoutine_Request>()
{
  return interfaces::srv::builder::Init_StartRoutine_Request_start();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_StartRoutine_Response_success
{
public:
  Init_StartRoutine_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::StartRoutine_Response success(::interfaces::srv::StartRoutine_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::StartRoutine_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::StartRoutine_Response>()
{
  return interfaces::srv::builder::Init_StartRoutine_Response_success();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__START_ROUTINE__BUILDER_HPP_
