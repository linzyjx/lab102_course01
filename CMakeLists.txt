cmake_minimum_required(VERSION 3.5)
project(CameraTest)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version:${OpenCV_VERSION}")
message(STATUS "    libraries:${OpenCV_LIBS}")
message(STATUS "    include path:${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(libcamera)

add_executable(Camera camera.cpp)
target_link_libraries(Camera ${OpenCV_LIBS})

add_executable(CameraThread thread.cpp)
target_link_libraries(CameraThread  ${OpenCV_LIBS} -lpthread)

add_executable(CameraOOP testCameraOOp.cpp)
target_link_libraries(CameraOOP  ${OpenCV_LIBS} camera -lpthread)
