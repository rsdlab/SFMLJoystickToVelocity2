// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  SFMLJoystickToVelocity2Test.cpp
 * @brief SFMLJoystick data convert to Velocity2D (test code)
 *
 */
// </rtc-template>

#include "SFMLJoystickToVelocity2Test.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const sfmljoysticktovelocity2_spec[] =
#else
static const char* sfmljoysticktovelocity2_spec[] =
#endif
  {
    "implementation_id", "SFMLJoystickToVelocity2Test",
    "type_name",         "SFMLJoystickToVelocity2Test",
    "description",       "SFMLJoystick data convert to Velocity2D",
    "version",           "1.0",
    "vendor",            "rsdlab",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    "conf.default.gainX", "0.01",
    "conf.default.gainTh", "0.01",
    "conf.default.xIndex", "0",

    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.gainX", "text",
    "conf.__widget__.gainTh", "text",
    "conf.__widget__.xIndex", "text",
    // Constraints

    "conf.__type__.debug", "int",
    "conf.__type__.gainX", "double",
    "conf.__type__.gainTh", "double",
    "conf.__type__.xIndex", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SFMLJoystickToVelocity2Test::SFMLJoystickToVelocity2Test(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inOut("in", m_in),
    m_velocityIn("velocity", m_velocity)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SFMLJoystickToVelocity2Test::~SFMLJoystickToVelocity2Test()
{
}



RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("velocity", m_velocityIn);
  
  // Set OutPort buffer
  addOutPort("in", m_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  bindParameter("gainX", m_gainX, "0.01");
  bindParameter("gainTh", m_gainTh, "0.01");
  bindParameter("xIndex", m_xIndex, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2Test::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool SFMLJoystickToVelocity2Test::runTest()
{
    return true;
}


extern "C"
{
 
  void SFMLJoystickToVelocity2TestInit(RTC::Manager* manager)
  {
    coil::Properties profile(sfmljoysticktovelocity2_spec);
    manager->registerFactory(profile,
                             RTC::Create<SFMLJoystickToVelocity2Test>,
                             RTC::Delete<SFMLJoystickToVelocity2Test>);
  }
  
}
