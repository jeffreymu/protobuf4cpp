cmake_minimum_required(VERSION 3.13)
project(jeffapp)

message("-- system arch:  ${CMAKE_SYSTEM_PROCESSOR}")
message("-- source path:  ${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_C_COMPILER gcc)#设置c语言的编译器为gcc
#set(CMAKE_CXX_COMPILER g++)#设置c++语言的编译器为g++

set (THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)

set(BOOST_ROOT "D:/boost_1_68_0")
set(BOOST_INCLUDEDIR, ${BOOST_ROOT}/include)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/libs)
set(BOOST_MIN_VERSION "1.68.0")
set(BOOST_NO_BOOST_CMAKE ON)

set(Boost_COMPILER -mgw81)#编译器后缀，将会在引用的库文件名字后加-mgw81
set(Boost_USE_MULTITHREADED ON)#启用多线程，将会在引用的库文件名字后加-mt
set(Boost_USE_STATIC_RUNTIME ON)#静态链接到C++运行库的库，将会在引用的库文件名字后加-s
set(Boost_USE_DEBUG_RUNTIME ON)#引入调试库，将会在引用的库文件名字后加-d，与Boost_USE_STATIC_RUNTIME参数合并为-sd
set(Boost_ARCHITECTURE -x64)#引用x64库，将会在引用的库文件名字后加-x64
set(Boost_USE_STATIC_LIBS ON)#引入静态链接库，对应.a后缀

#Boost开启以下三个参数，以便查错
set(Boost_DEBUG ON)
set(Boost_DETAILED_FAILURE_MSG ON)
set(Boost_REALPATH ON)

FIND_PACKAGE(Boost ${BOOST_MIN_VERSION} REQUIRED COMPONENTS)

set(PROTOBUF_ROOT "D:/protobuf")
set(PROTOBUF_INCLUDE_DIR, ${PROTOBUF_ROOT}/include)
set(Protobuf_LIBRARIES ${PROTOBUF_ROOT}/lib)
include(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)

if (Protobuf_FOUND)
    include_directories(${PROTOBUF_INCLUDE_DIR})
    link_directories(${Protobuf_LIBRARIES})
    message(STATUS "Setting up Protobuf")
    message(STATUS " Include - ${PROTOBUF_INCLUDE_DIR}")
    message(STATUS " Library  - ${Protobuf_LIBRARIES}")
    message(STATUS "Using Protocol Buffers ${Protobuf_VERSION}")
else()
    message(FATAL_ERROR "PROTOBUF NOT FOUNED")
endif (Protobuf_FOUND)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error: Boost (version >= 1.55) required.")
else()
    message(STATUS "Setting up BOOST")
    message(STATUS " Include - ${Boost_INCLUDE_DIRS}")
    message(STATUS " Library  - ${Boost_LIBRARY_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif (NOT Boost_FOUND)

# boost include
#include_directories(${BOOST_ROOT}/boost)
#link_directories(jeffapp ${BOOST_LIBRARYDIR})
#target_link_libraries(jeffapp boost_thread-mt boost-system)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -ffunction-sections -O0")

# project
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(src/Header)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/proto)

add_executable(${PROJECT_NAME}
        main.cpp
        src/Source/IamAClass.cpp)

target_link_libraries( ${PROJECT_NAME} proto
        ${Protobuf_LIBRARIES})

