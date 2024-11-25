// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/StartRoutine.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__START_ROUTINE__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__START_ROUTINE__TRAITS_HPP_

#include "interfaces/srv/detail/start_routine__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::StartRoutine_Request>()
{
  return "interfaces::srv::StartRoutine_Request";
}

template<>
inline const char * name<interfaces::srv::StartRoutine_Request>()
{
  return "interfaces/srv/StartRoutine_Request";
}

template<>
struct has_fixed_size<interfaces::srv::StartRoutine_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::StartRoutine_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::StartRoutine_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::StartRoutine_Response>()
{
  return "interfaces::srv::StartRoutine_Response";
}

template<>
inline const char * name<interfaces::srv::StartRoutine_Response>()
{
  return "interfaces/srv/StartRoutine_Response";
}

template<>
struct has_fixed_size<interfaces::srv::StartRoutine_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::StartRoutine_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::StartRoutine_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::StartRoutine>()
{
  return "interfaces::srv::StartRoutine";
}

template<>
inline const char * name<interfaces::srv::StartRoutine>()
{
  return "interfaces/srv/StartRoutine";
}

template<>
struct has_fixed_size<interfaces::srv::StartRoutine>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::StartRoutine_Request>::value &&
    has_fixed_size<interfaces::srv::StartRoutine_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::StartRoutine>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::StartRoutine_Request>::value &&
    has_bounded_size<interfaces::srv::StartRoutine_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::StartRoutine>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::StartRoutine_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::StartRoutine_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__START_ROUTINE__TRAITS_HPP_
