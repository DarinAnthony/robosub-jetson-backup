// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/ArmPixhawk.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ARM_PIXHAWK__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__ARM_PIXHAWK__TRAITS_HPP_

#include "interfaces/srv/detail/arm_pixhawk__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::ArmPixhawk_Request>()
{
  return "interfaces::srv::ArmPixhawk_Request";
}

template<>
inline const char * name<interfaces::srv::ArmPixhawk_Request>()
{
  return "interfaces/srv/ArmPixhawk_Request";
}

template<>
struct has_fixed_size<interfaces::srv::ArmPixhawk_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::ArmPixhawk_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::ArmPixhawk_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::ArmPixhawk_Response>()
{
  return "interfaces::srv::ArmPixhawk_Response";
}

template<>
inline const char * name<interfaces::srv::ArmPixhawk_Response>()
{
  return "interfaces/srv/ArmPixhawk_Response";
}

template<>
struct has_fixed_size<interfaces::srv::ArmPixhawk_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::ArmPixhawk_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::ArmPixhawk_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::ArmPixhawk>()
{
  return "interfaces::srv::ArmPixhawk";
}

template<>
inline const char * name<interfaces::srv::ArmPixhawk>()
{
  return "interfaces/srv/ArmPixhawk";
}

template<>
struct has_fixed_size<interfaces::srv::ArmPixhawk>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::ArmPixhawk_Request>::value &&
    has_fixed_size<interfaces::srv::ArmPixhawk_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::ArmPixhawk>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::ArmPixhawk_Request>::value &&
    has_bounded_size<interfaces::srv::ArmPixhawk_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::ArmPixhawk>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::ArmPixhawk_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::ArmPixhawk_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__ARM_PIXHAWK__TRAITS_HPP_
