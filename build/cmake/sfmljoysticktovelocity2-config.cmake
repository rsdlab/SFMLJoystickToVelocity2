# SFMLJoystickToVelocity2 CMake config file
#
# This file sets the following variables:
# SFMLJoystickToVelocity2_FOUND - Always TRUE.
# SFMLJoystickToVelocity2_INCLUDE_DIRS - Directories containing the SFMLJoystickToVelocity2 include files.
# SFMLJoystickToVelocity2_IDL_DIRS - Directories containing the SFMLJoystickToVelocity2 IDL files.
# SFMLJoystickToVelocity2_LIBRARIES - Libraries needed to use SFMLJoystickToVelocity2.
# SFMLJoystickToVelocity2_DEFINITIONS - Compiler flags for SFMLJoystickToVelocity2.
# SFMLJoystickToVelocity2_VERSION - The version of SFMLJoystickToVelocity2 found.
# SFMLJoystickToVelocity2_VERSION_MAJOR - The major version of SFMLJoystickToVelocity2 found.
# SFMLJoystickToVelocity2_VERSION_MINOR - The minor version of SFMLJoystickToVelocity2 found.
# SFMLJoystickToVelocity2_VERSION_REVISION - The revision version of SFMLJoystickToVelocity2 found.
# SFMLJoystickToVelocity2_VERSION_CANDIDATE - The candidate version of SFMLJoystickToVelocity2 found.

message(STATUS "Found SFMLJoystickToVelocity2-")
set(SFMLJoystickToVelocity2_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(SFMLJoystickToVelocity2_INCLUDE_DIRS
#    "/usr/local/include/sfmljoysticktovelocity2-"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(SFMLJoystickToVelocity2_IDL_DIRS
#    "/usr/local/include/sfmljoysticktovelocity2-/idl")
set(SFMLJoystickToVelocity2_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(SFMLJoystickToVelocity2_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(SFMLJoystickToVelocity2_LIBRARIES
        "/usr/local//libsfmljoysticktovelocity2.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(SFMLJoystickToVelocity2_LIBRARIES
        "/usr/local//libsfmljoysticktovelocity2.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(SFMLJoystickToVelocity2_DEFINITIONS ${<dependency>_DEFINITIONS})

set(SFMLJoystickToVelocity2_VERSION )
set(SFMLJoystickToVelocity2_VERSION_MAJOR )
set(SFMLJoystickToVelocity2_VERSION_MINOR )
set(SFMLJoystickToVelocity2_VERSION_REVISION )
set(SFMLJoystickToVelocity2_VERSION_CANDIDATE )

