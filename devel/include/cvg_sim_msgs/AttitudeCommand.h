// Generated by gencpp from file cvg_sim_msgs/AttitudeCommand.msg
// DO NOT EDIT!


#ifndef CVG_SIM_MSGS_MESSAGE_ATTITUDECOMMAND_H
#define CVG_SIM_MSGS_MESSAGE_ATTITUDECOMMAND_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace cvg_sim_msgs
{
template <class ContainerAllocator>
struct AttitudeCommand_
{
  typedef AttitudeCommand_<ContainerAllocator> Type;

  AttitudeCommand_()
    : header()
    , roll(0.0)
    , pitch(0.0)  {
    }
  AttitudeCommand_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , roll(0.0)
    , pitch(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _roll_type;
  _roll_type roll;

   typedef float _pitch_type;
  _pitch_type pitch;




  typedef boost::shared_ptr< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> const> ConstPtr;

}; // struct AttitudeCommand_

typedef ::cvg_sim_msgs::AttitudeCommand_<std::allocator<void> > AttitudeCommand;

typedef boost::shared_ptr< ::cvg_sim_msgs::AttitudeCommand > AttitudeCommandPtr;
typedef boost::shared_ptr< ::cvg_sim_msgs::AttitudeCommand const> AttitudeCommandConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cvg_sim_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'cvg_sim_msgs': ['/home/esteban/tum_simulator_ws/src/tum-simulator-indigo/cvg_sim_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cceacd88dad80f3e3fd1466d24264ec6";
  }

  static const char* value(const ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcceacd88dad80f3eULL;
  static const uint64_t static_value2 = 0x3fd1466d24264ec6ULL;
};

template<class ContainerAllocator>
struct DataType< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cvg_sim_msgs/AttitudeCommand";
  }

  static const char* value(const ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float32 roll\n\
float32 pitch\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.roll);
      stream.next(m.pitch);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AttitudeCommand_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cvg_sim_msgs::AttitudeCommand_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CVG_SIM_MSGS_MESSAGE_ATTITUDECOMMAND_H
