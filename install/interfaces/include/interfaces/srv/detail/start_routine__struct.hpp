// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/StartRoutine.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__START_ROUTINE__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__START_ROUTINE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__StartRoutine_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__StartRoutine_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartRoutine_Request_
{
  using Type = StartRoutine_Request_<ContainerAllocator>;

  explicit StartRoutine_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start = false;
    }
  }

  explicit StartRoutine_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start = false;
    }
  }

  // field types and members
  using _start_type =
    bool;
  _start_type start;

  // setters for named parameter idiom
  Type & set__start(
    const bool & _arg)
  {
    this->start = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::StartRoutine_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::StartRoutine_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::StartRoutine_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::StartRoutine_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__StartRoutine_Request
    std::shared_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__StartRoutine_Request
    std::shared_ptr<interfaces::srv::StartRoutine_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartRoutine_Request_ & other) const
  {
    if (this->start != other.start) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartRoutine_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartRoutine_Request_

// alias to use template instance with default allocator
using StartRoutine_Request =
  interfaces::srv::StartRoutine_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__StartRoutine_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__StartRoutine_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartRoutine_Response_
{
  using Type = StartRoutine_Response_<ContainerAllocator>;

  explicit StartRoutine_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit StartRoutine_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    interfaces::srv::StartRoutine_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::StartRoutine_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::StartRoutine_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::StartRoutine_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__StartRoutine_Response
    std::shared_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__StartRoutine_Response
    std::shared_ptr<interfaces::srv::StartRoutine_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartRoutine_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartRoutine_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartRoutine_Response_

// alias to use template instance with default allocator
using StartRoutine_Response =
  interfaces::srv::StartRoutine_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct StartRoutine
{
  using Request = interfaces::srv::StartRoutine_Request;
  using Response = interfaces::srv::StartRoutine_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__START_ROUTINE__STRUCT_HPP_
