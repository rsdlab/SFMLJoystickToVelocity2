cmake_minimum_required (VERSION 3.5)
 
project (TestRos2Serializer
    VERSION 1.0
    LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#OpenRTM-aistの検出
find_package(OpenRTM 2.0 REQUIRED)
find_package(ROS2Transport REQUIRED)

#ROS2の検出
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

#FastDDSの検出
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)


if(WIN32)
	add_definitions(-DNOGDI)
	add_definitions(-DRTM_SKEL_IMPORT_SYMBOL)
endif()

#インクルードディレクトリ、リンクディレクトリ、コンパイル時のフラグの設定
include_directories(${OPENRTM_INCLUDE_DIRS})
add_definitions(${OPENRTM_CFLAGS})

link_directories(${OPENRTM_LIBRARY_DIRS})

#動的リンクライブラリの生成
add_library(${PROJECT_NAME} SHARED TestRos2Serializer.cpp)


#生成するライブラリ名をTestRos2Serializer.dll(もしくは.so)に設定
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")


target_include_directories(${PROJECT_NAME} SYSTEM
		PUBLIC ${rclcpp_INCLUDE_DIRS}
		PUBLIC ${std_msgs_INCLUDE_DIRS}
		PUBLIC ${geometry_msgs_INCLUDE_DIRS}
		PUBLIC ${sensor_msgs_INCLUDE_DIRS}
		PUBLIC ${ROS2TRANSPORT_INCLUDE_DIRS})

#OpenRTM-aistのライブラリとリンク
target_link_libraries(${PROJECT_NAME} ${OPENRTM_LIBRARIES} ${ROS2TRANSPORT_LIBRARIES}
		${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES} ${geometry_msgs_LIBRARIES} ${sensor_msgs_LIBRARIES} 
		${std_msgs_LIBRARIES__rosidl_typesupport_fastrtps_cpp} 
		${geometry_msgs_LIBRARIES__rosidl_typesupport_fastrtps_cpp} 
		${sensor_msgs_LIBRARIES__rosidl_typesupport_fastrtps_cpp}
		fastcdr fastrtps)

target_compile_definitions(${PROJECT_NAME} PRIVATE STD_MSGS_VERSION_MAJOR=${std_msgs_VERSION_MAJOR} 
								GEOMETORY_MSGS_VERSION_MAJOR=${geometry_msgs_VERSION_MAJOR} 
								SENSOR_MSGS_VERSION_MAJOR=${sensor_msgs_VERSION_MAJOR} 
								STD_MSGS_VERSION_MINOR=${std_msgs_VERSION_MINOR} 
								GEOMETORY_MSGS_VERSION_MINOR=${geometry_msgs_VERSION_MINOR} 
								SENSOR_MSGS_VERSION_MINOR==${sensor_msgs_VERSION_MINOR})

if(${rclcpp_VERSION_MAJOR} GREATER 1)
	set_target_properties(${PROJECT_NAME} PROPERTIES
			POSITION_INDEPENDENT_CODE ON
			CXX_STANDARD 14
			CXX_EXTENSIONS OFF
			CXX_STANDARD_REQUIRED ON
	)
endif()