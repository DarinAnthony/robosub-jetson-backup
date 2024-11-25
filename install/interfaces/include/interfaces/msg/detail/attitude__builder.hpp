// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_

#include "interfaces/msg/detail/attitude__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Attitude_yawspeed
{
public:
  explicit Init_Attitude_yawspeed(::interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Attitude yawspeed(::interfaces::msg::Attitude::_yawspeed_type arg)
  {
    msg_.yawspeed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Attitude msg_;
};

class Init_Attitude_pitchspeed
{
public:
  explicit Init_Attitude_pitchspeed(::interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_yawspeed pitchspeed(::interfaces::msg::Attitude::_pitchspeed_type arg)
  {
    msg_.pitchspeed = std::move(arg);
    return Init_Attitude_yawspeed(msg_);
  }

private:
  ::interfaces::msg::Attitude msg_;
};

class Init_Attitude_rollspeed
{
public:
  explicit Init_Attitude_rollspeed(::interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_pitchspeed rollspeed(::interfaces::msg::Attitude::_rollspeed_type arg)
  {
    msg_.rollspeed = std::move(arg);
    return Init_Attitude_pitchspeed(msg_);
  }

private:
  ::interfaces::msg::Attitude msg_;
};

class Init_Attitude_yaw
{
public:
  explicit Init_Attitude_yaw(::interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_rollspeed yaw(::interfaces::msg::Attitude::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Attitude_rollspeed(msg_);
  }

private:
  ::interfaces::msg::Attitude msg_;
};

class Init_Attitude_pitch
{
public:
  explicit Init_Attitude_pitch(::interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_yaw pitch(::interfaces::msg::Attitude::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Attitude_yaw(msg_);
  }

private:
  ::interfaces::msg::Attitude msg_;
};

class Init_Attitude_roll
{
public:
  Init_Attitude_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Attitude_pitch roll(::interfaces::msg::Attitude::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Attitude_pitch(msg_);
  }

private:
  ::interfaces::msg::Attitude msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Attitude>()
{
  return interfaces::msg::builder::Init_Attitude_roll();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
