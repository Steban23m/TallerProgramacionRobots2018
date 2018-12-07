// Generated by gencpp from file ardrone_autonomy/navdata_phys_measures.msg
// DO NOT EDIT!


#ifndef ARDRONE_AUTONOMY_MESSAGE_NAVDATA_PHYS_MEASURES_H
#define ARDRONE_AUTONOMY_MESSAGE_NAVDATA_PHYS_MEASURES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ardrone_autonomy
{
template <class ContainerAllocator>
struct navdata_phys_measures_
{
  typedef navdata_phys_measures_<ContainerAllocator> Type;

  navdata_phys_measures_()
    : header()
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , accs_temp(0.0)
    , gyro_temp(0)
    , phys_accs()
    , phys_gyros()
    , alim3V3(0)
    , vrefEpson(0)
    , vrefIDG(0)  {
    }
  navdata_phys_measures_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , accs_temp(0.0)
    , gyro_temp(0)
    , phys_accs(_alloc)
    , phys_gyros(_alloc)
    , alim3V3(0)
    , vrefEpson(0)
    , vrefIDG(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _drone_time_type;
  _drone_time_type drone_time;

   typedef uint16_t _tag_type;
  _tag_type tag;

   typedef uint16_t _size_type;
  _size_type size;

   typedef float _accs_temp_type;
  _accs_temp_type accs_temp;

   typedef uint16_t _gyro_temp_type;
  _gyro_temp_type gyro_temp;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _phys_accs_type;
  _phys_accs_type phys_accs;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _phys_gyros_type;
  _phys_gyros_type phys_gyros;

   typedef uint32_t _alim3V3_type;
  _alim3V3_type alim3V3;

   typedef uint32_t _vrefEpson_type;
  _vrefEpson_type vrefEpson;

   typedef uint32_t _vrefIDG_type;
  _vrefIDG_type vrefIDG;




  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> const> ConstPtr;

}; // struct navdata_phys_measures_

typedef ::ardrone_autonomy::navdata_phys_measures_<std::allocator<void> > navdata_phys_measures;

typedef boost::shared_ptr< ::ardrone_autonomy::navdata_phys_measures > navdata_phys_measuresPtr;
typedef boost::shared_ptr< ::ardrone_autonomy::navdata_phys_measures const> navdata_phys_measuresConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ardrone_autonomy

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'ardrone_autonomy': ['/home/esteban/tum_simulator_ws/src/ardrone_autonomy/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
{
  static const char* value()
  {
    return "649dd469618f5ff313f6bceab2c356b7";
  }

  static const char* value(const ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x649dd469618f5ff3ULL;
  static const uint64_t static_value2 = 0x13f6bceab2c356b7ULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ardrone_autonomy/navdata_phys_measures";
  }

  static const char* value(const ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 drone_time\n\
uint16 tag\n\
uint16 size\n\
float32 accs_temp\n\
uint16 gyro_temp\n\
float32[] phys_accs\n\
float32[] phys_gyros\n\
uint32 alim3V3\n\
uint32 vrefEpson\n\
uint32 vrefIDG\n\
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

  static const char* value(const ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.drone_time);
      stream.next(m.tag);
      stream.next(m.size);
      stream.next(m.accs_temp);
      stream.next(m.gyro_temp);
      stream.next(m.phys_accs);
      stream.next(m.phys_gyros);
      stream.next(m.alim3V3);
      stream.next(m.vrefEpson);
      stream.next(m.vrefIDG);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navdata_phys_measures_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ardrone_autonomy::navdata_phys_measures_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "drone_time: ";
    Printer<double>::stream(s, indent + "  ", v.drone_time);
    s << indent << "tag: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.tag);
    s << indent << "size: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.size);
    s << indent << "accs_temp: ";
    Printer<float>::stream(s, indent + "  ", v.accs_temp);
    s << indent << "gyro_temp: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.gyro_temp);
    s << indent << "phys_accs[]" << std::endl;
    for (size_t i = 0; i < v.phys_accs.size(); ++i)
    {
      s << indent << "  phys_accs[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.phys_accs[i]);
    }
    s << indent << "phys_gyros[]" << std::endl;
    for (size_t i = 0; i < v.phys_gyros.size(); ++i)
    {
      s << indent << "  phys_gyros[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.phys_gyros[i]);
    }
    s << indent << "alim3V3: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.alim3V3);
    s << indent << "vrefEpson: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.vrefEpson);
    s << indent << "vrefIDG: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.vrefIDG);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDRONE_AUTONOMY_MESSAGE_NAVDATA_PHYS_MEASURES_H
