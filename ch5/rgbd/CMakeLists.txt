#project(joinMap)
#
#cmake_minimum_required(VERSION 3.16)
#
#find_package(Sophus REQUIRED)
#include_directories(${Sophus_INCLUDE_DIRS})
#
#find_package(Pangolin REQUIRED)
#find_package(OpenCV REQUIRED)
##添加头文件
#include_directories(( ${OpenCV_INCLUDE_DIRS}))
#add_executable(joinMap joinMap.cpp)
#target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES} ${Sophus_LIBRARIES})
project(joinMap)

cmake_minimum_required(VERSION 3.16)

find_package(Sophus REQUIRED)
find_package(Pangolin REQUIRED)
find_package(OpenCV REQUIRED)

# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})

#set(CMAKE_PREFIX_PATH "/usr/local/include/sophus")

add_executable(joinMap joinMap.cpp
        test.cpp)
target_include_directories(joinMap PRIVATE ${Sophus_INCLUDE_DIRS})
target_link_libraries(joinMap PRIVATE ${OpenCV_LIBS} ${Pangolin_LIBRARIES} ${Sophus_LIBRARIES} fmt)

add_executable(test test.cpp)
