// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/DisarmPixhawk.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__DisarmPixhawk_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__DisarmPixhawk_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DisarmPixhawk_Request_
{
  using Type = DisarmPixhawk_Request_<ContainerAllocator>;

  explicit DisarmPixhawk_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timeoutms = 0ll;
    }
  }

  explicit DisarmPixhawk_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timeoutms = 0ll;
    }
  }

  // field types and members
  using _timeoutms_type =
    int64_t;
  _timeoutms_type timeoutms;

  // setters for named parameter idiom
  Type & set__timeoutms(
    const int64_t & _arg)
  {
    this->timeoutms = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__DisarmPixhawk_Request
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__DisarmPixhawk_Request
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DisarmPixhawk_Request_ & other) const
  {
    if (this->timeoutms != other.timeoutms) {
      return false;
    }
    return true;
  }
  bool operator!=(const DisarmPixhawk_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DisarmPixhawk_Request_

// alias to use template instance with default allocator
using DisarmPixhawk_Request =
  interfaces::srv::DisarmPixhawk_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__DisarmPixhawk_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__DisarmPixhawk_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DisarmPixhawk_Response_
{
  using Type = DisarmPixhawk_Response_<ContainerAllocator>;

  explicit DisarmPixhawk_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit DisarmPixhawk_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__DisarmPixhawk_Response
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__DisarmPixhawk_Response
    std::shared_ptr<interfaces::srv::DisarmPixhawk_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DisarmPixhawk_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const DisarmPixhawk_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DisarmPixhawk_Response_

// alias to use template instance with default allocator
using DisarmPixhawk_Response =
  interfaces::srv::DisarmPixhawk_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct DisarmPixhawk
{
  using Request = interfaces::srv::DisarmPixhawk_Request;
  using Response = interfaces::srv::DisarmPixhawk_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__DISARM_PIXHAWK__STRUCT_HPP_
