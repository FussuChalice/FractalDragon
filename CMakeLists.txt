# CMakeList.txt : CMake project for HarterHatewayFractal, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("HarterHatewayFractal")

# Add source to this project's executable.
add_executable (HarterHatewayFractal "HarterHatewayFractal.cpp" "HarterHatewayFractal.h"   "pch.h" )


target_link_libraries(HarterHatewayFractal 
		${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-network.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-system.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-window.lib
)

include_directories(${CMAKE_SOURCE_DIR}/include)

# move assets files to output buid directory
set(FONT_FILE ${CMAKE_SOURCE_DIR}/assets/arial.ttf)
configure_file(${FONT_FILE} ${CMAKE_CURRENT_BINARY_DIR}/arial.ttf COPYONLY)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HarterHatewayFractal PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
