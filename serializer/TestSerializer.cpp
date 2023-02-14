#include <rtm/ByteDataStreamBase.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <coil/Factory.h>
#include <rtm/Manager.h>
#include <geometry_msgs/Twist.h>
#include"ROSSerializer.h"
#include"ROSMessageInfo.h"

//以下はシリアライザの実装
class TestSerializer : public RTC::ROSSerializerBase<RTC::TimedVelocity2D>
{
public:
    TestSerializer(){};

    
 
    bool serialize(const RTC::TimedVelocity2D& data) override
    {
      geometry_msgs::Twist msg;
      //msg.header.stamp.sec = data.tm.sec;
      //msg.header.stamp.nsec = data.tm.nsec;
        msg.linear.x = data.data.vx;
        msg.linear.y = data.data.vy;
        msg.angular.z = data.data.va;

      //printf("%f,%f,%f",msg.linear.x,msg.linear.y,msg.angular.z);
      ROSSerializerBase<RTC::TimedVelocity2D>::m_message = ros::serialization::serializeMessage<geometry_msgs::Twist>(msg);
      return true;
      
    }
    bool deserialize(RTC::TimedVelocity2D& data) override
{
    geometry_msgs::Twist msg;
    ros::serialization::deserializeMessage(ROSSerializerBase<RTC::TimedVelocity2D>::m_message, msg);
    data.data.vx = msg.linear.x;
    data.data.vy = msg.linear.y;
    data.data.va = msg.angular.z;
    
    return false;
}
private:

};

extern "C"
{
    //以下はモジュールロード時に呼び出される関数
    DLL_EXPORT void TestSerializerInit(RTC::Manager* manager)
    {
        //以下のファクトリはデータ型ごとに登録する必要がある
        RTC::addSerializer<RTC::TimedVelocity2D,TestSerializer>("velocity");
        //ROSTransportにROSに送るメッセージ型を提示する
        RTC::GlobalROSMessageInfoList:: instance().addInfo("velocity", new RTC::ROSMessageInfo<geometry_msgs::Twist>()); 
    };
}