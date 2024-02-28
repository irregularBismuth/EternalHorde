cmake_minimum_required(VERSION 3.10)

project(eternal_horde)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

file(GLOB PROJECT_SOURCES "source/src/*.cpp")
file(GLOB PROJECT_HEADERS "source/include/*.h")

# Optionally, automatically add the include directory
include_directories("source/include")

#add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

