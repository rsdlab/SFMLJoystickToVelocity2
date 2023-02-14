// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  SFMLJoystickToVelocity2.cpp
 * @brief SFMLJoystick data convert to Velocity2D
 *
 */
// </rtc-template>

#include "SFMLJoystickToVelocity2.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const sfmljoysticktovelocity2_spec[] =
#else
static const char* sfmljoysticktovelocity2_spec[] =
#endif
  {
    "implementation_id", "SFMLJoystickToVelocity2",
    "type_name",         "SFMLJoystickToVelocity2",
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
SFMLJoystickToVelocity2::SFMLJoystickToVelocity2(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in),
    m_velocityOut("velocity", m_velocity)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SFMLJoystickToVelocity2::~SFMLJoystickToVelocity2()
{
}



RTC::ReturnCode_t SFMLJoystickToVelocity2::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  addOutPort("velocity", m_velocityOut);

  
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
  bindParameter("thIndex", m_thIndex, "1");
  // </rtc-template>

  
  return RTC::RTC_OK;
}



RTC::ReturnCode_t SFMLJoystickToVelocity2::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SFMLJoystickToVelocity2::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  m_velocity.data.vx = 0;
	m_velocity.data.vy = 0;
	m_velocity.data.va = 0;
	m_velocityOut.write();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SFMLJoystickToVelocity2::onExecute(RTC::UniqueId /*ec_id*/)
{
  if(m_inIn.isNew()) {
		m_inIn.read();



		if(m_in.data.length() <= m_xIndex || m_in.data.length() <= m_thIndex) {
			std::cout << "[RTC::SFMLJoystickToVelocity] Too short Sequence Input." << std::endl;
			return RTC::RTC_ERROR;
		}

		m_velocity.data.vx = m_gainX * m_in.data[m_xIndex];
		m_velocity.data.vy = 0;
		m_velocity.data.va = m_gainTh * m_in.data[m_thIndex];
		m_velocityOut.write();

		if(m_debug) {
			std::cout << "[RTC::SFMLJoystickToVelocity] Velocity = " << m_velocity.data.vx << ", " << m_velocity.data.vy << ", " << m_velocity.data.va << std::endl;
		}
	}

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t SFMLJoystickToVelocity2::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SFMLJoystickToVelocity2::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void SFMLJoystickToVelocity2Init(RTC::Manager* manager)
  {
    coil::Properties profile(sfmljoysticktovelocity2_spec);
    manager->registerFactory(profile,
                             RTC::Create<SFMLJoystickToVelocity2>,
                             RTC::Delete<SFMLJoystickToVelocity2>);
  }
  
}
