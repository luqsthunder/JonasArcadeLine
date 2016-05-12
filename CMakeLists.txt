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
file(GLOB CORESRCS   "${PROJECT_SOURCE_DIR}/src/core/*.cpp")

add_executable( ${EXECUTABLE_NAME}
                ${SRCMAIN}
                ${CORESRCS})

#findind SLD2
find_package(SFML 2 COMPONENTS system audio graphics window REQUIRED)

#adding libs to executable
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
