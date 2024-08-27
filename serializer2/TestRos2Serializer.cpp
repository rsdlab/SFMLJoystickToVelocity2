#include <rtm/ByteDataStreamBase.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <coil/Factory.h>
#include <rtm/Manager.h>
#include <geometry_msgs/msg/twist.hpp>
#if (STD_MSGS_VERSION_MAJOR >= 2)
#include <geometry_msgs/msg/detail/twist__rosidl_typesupport_fastrtps_cpp.hpp>
#else
#include <geometry_msgs/msg/twist__rosidl_typesupport_fastrtps_cpp.hpp>
#endif
#include <rtm/ext/ROS2Transport/ROS2Serializer.h>


//以下はシリアライザの実装
class TestRos2Serializer : public RTC::ROS2SerializerBase<RTC::TimedVelocity2D>
{
public:
    TestRos2Serializer(){};

    
 
    bool serialize(const RTC::TimedVelocity2D& data) override
    {
      geometry_msgs::msg::Twist msg;
      //msg.header.stamp.sec = data.tm.sec;
      //msg.header.stamp.nsec = data.tm.nsec;
        msg.linear.x = data.data.va;
        msg.linear.y = data.data.vy;
        msg.angular.z = -data.data.vx;

      //printf("%f,%f,%f",msg.linear.x,msg.linear.y,msg.angular.z);
      return RTC::ROS2SerializerBase<RTC::TimedVelocity2D>::geometrymsg_serialize(msg);
      
    }
    bool deserialize(RTC::TimedVelocity2D& data) override
{
    geometry_msgs::msg::Twist msg;
    bool ret = ROS2SerializerBase<RTC::TimedVelocity2D>::geometrymsg_deserialize(msg);

    data.data.vx = -msg.linear.x;
    data.data.vy = msg.linear.y;
    data.data.va = msg.angular.z;
    
    return ret;
}
private:

};

extern "C"
{
    //以下はモジュールロード時に呼び出される関数
    DLL_EXPORT void TestRos2SerializerInit(RTC::Manager* manager)
    {
        //以下のファクトリはデータ型ごとに登録する必要がある
        RTC::addRos2Serializer<RTC::TimedVelocity2D, geometry_msgs::msg::Twist, TestRos2Serializer>("velocity");
        //ROSTransportにROSに送るメッセージ型を提示する
        //RTC::GlobalROSMessageInfoList:: instance().addInfo("velocity", new RTC::ROSMessageInfo<geometry_msgs::msg::Twist>()); 
    };
}
