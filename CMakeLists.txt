cmake_minimum_required(VERSION 3.1)
project(JonasArcadeProject)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

#setting to user c++ 11
set(CMAKE_CXX_FLAGS "-std=c++0x")

#setting a name to executable
set(EXECUTABLE_NAME "JonasArcade")

#including dir
include_directories("${PROJECT_SOURCE_DIR}/src")

#colocando para compilar os arquivos sem pastas
file(GLOB SRCMAIN   "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable( ${EXECUTABLE_NAME}
                ${SRCMAIN} src/core/Ball.cpp src/core/Ball.h)

#findind SLD2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

#adding libs to executable
if(SDL2_FOUND)
  include_directories(${SDL2_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARY})
endif()

if(SDL2_IMAGE_FOUND)
  include_directories(${SDL2_IMAGE_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SDL2_IMAGE_LIBRARY})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
