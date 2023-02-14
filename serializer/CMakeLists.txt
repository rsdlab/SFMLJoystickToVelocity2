set(comp_srcs TestSerializer.cpp )


project (TestSerializer
    VERSION 1.0
    LANGUAGES CXX)
#include("${PROJECT_SOURCE_DIR}/cmake/utils.cmake") 

message(STATUS ${MSVC_TOOLSET_VERSION})

find_package(OpenRTM 2.0 REQUIRED)
find_package(roscpp)


if(roscpp_FOUND)
  message("roscpp Found")
endif()

if(NOT roscpp_FOUND)
	message(FATAL_ERROR "can not find roscpp.")
endif()

find_package(Boost 1.69 COMPONENTS chrono filesystem system)
if(NOT Boost_FOUND)
	find_package(Boost REQUIRED COMPONENTS chrono filesystem signals system)
endif()

#インクルードディレクトリ、リンクディレクトリ、コンパイル時のフラグの設定
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME})
include_directories(${PROJECT_BINARY_DIR})
#include_directories(${PROJECT_BINARY_DIR}/idl)
include_directories(${OPENRTM_INCLUDE_DIRS})
add_definitions(${OPENRTM_CFLAGS})

link_directories(${OPENRTM_LIBRARY_DIRS})
link_directories(${roscpp_LIBRARY_DIRS})

#動的リンクライブラリの生成
add_library(${PROJECT_NAME} SHARED TestSerializer.cpp ${ALL_IDL_SRCS})
set_source_files_properties(${ALL_IDL_SRCS} PROPERTIES GENERATED 1) 
if(NOT TARGET ALL_IDL_TGT)
add_custom_target(ALL_IDL_TGT) 
endif(NOT TARGET ALL_IDL_TGT) 
add_dependencies(${PROJECT_NAME} ALL_IDL_TGT) 

#生成するライブラリ名をTestSerializer.dll(もしくは.so)に設定
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
#OpenRTM-aistのライブラリとリンク
target_include_directories(${PROJECT_NAME} SYSTEM
		PRIVATE ${roscpp_INCLUDE_DIRS}
		PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENRTM_LIBRARIES} ${roscpp_LIBRARIES} ${Boost_LIBRARIES} /usr/lib/x86_64-linux-gnu/openrtm-2.0/transport/ROSTransport.so )