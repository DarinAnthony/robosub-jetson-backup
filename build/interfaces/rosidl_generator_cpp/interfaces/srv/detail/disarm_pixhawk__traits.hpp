// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/DisarmPixhawk.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__TRAITS_HPP_

#include "interfaces/srv/detail/disarm_pixhawk__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::DisarmPixhawk_Request>()
{
  return "interfaces::srv::DisarmPixhawk_Request";
}

template<>
inline const char * name<interfaces::srv::DisarmPixhawk_Request>()
{
  return "interfaces/srv/DisarmPixhawk_Request";
}

template<>
struct has_fixed_size<interfaces::srv::DisarmPixhawk_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::DisarmPixhawk_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::DisarmPixhawk_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::DisarmPixhawk_Response>()
{
  return "interfaces::srv::DisarmPixhawk_Response";
}

template<>
inline const char * name<interfaces::srv::DisarmPixhawk_Response>()
{
  return "interfaces/srv/DisarmPixhawk_Response";
}

template<>
struct has_fixed_size<interfaces::srv::DisarmPixhawk_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::DisarmPixhawk_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::DisarmPixhawk_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::DisarmPixhawk>()
{
  return "interfaces::srv::DisarmPixhawk";
}

template<>
inline const char * name<interfaces::srv::DisarmPixhawk>()
{
  return "interfaces/srv/DisarmPixhawk";
}

template<>
struct has_fixed_size<interfaces::srv::DisarmPixhawk>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::DisarmPixhawk_Request>::value &&
    has_fixed_size<interfaces::srv::DisarmPixhawk_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::DisarmPixhawk>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::DisarmPixhawk_Request>::value &&
    has_bounded_size<interfaces::srv::DisarmPixhawk_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::DisarmPixhawk>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::DisarmPixhawk_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::DisarmPixhawk_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__TRAITS_HPP_
