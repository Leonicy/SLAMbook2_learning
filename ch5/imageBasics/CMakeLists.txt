project(imageBasics)

#添加
#添加c++ 11标准支持
#set(CMAKE_CXX_FLAGS "std=c++11")
#寻找opencv库
find_package(OpenCV REQUIRED)
#添加头文件
include_directories(( ${OpenCV_INCLUDE_DIRS}))
#
add_executable(imageBasics imageBasics.cpp
        test.cpp)
# 链接OpenCV库
target_link_libraries(imageBasics ${OpenCV_LIBS})

add_executable(undistortImage undistortImage.cpp)
# 链接OpenCV库
target_link_libraries(undistortImage ${OpenCV_LIBS})

add_executable(test test.cpp)
# 链接OpenCV库
target_link_libraries(test ${OpenCV_LIBS})
