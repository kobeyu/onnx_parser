cmake_minimum_required (VERSION 3.5)

project(onnx_parser CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Build information
message(STATUS "Build Configuration: ${CMAKE_BUILD_TYPE}")
message(STATUS "Build executables in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_definitions(-std=c++11)

# Source directories
set(INC_ONNX_DIR /home/kobeyu/workspace/onnx_project/onnx/install/include)
set(LIB_ONNX_DIR /home/kobeyu/workspace/onnx_project/onnx/install/lib)
set(INC_PROTO_DIR /home/kobeyu/workspace/onnx_project/protobuf/install/include)
set(LIB_PROTO_DIR /home/kobeyu/workspace/onnx_project/protobuf/install/lib)

# Include directories
include_directories( ${INC_ONNX_DIR} ${INC_PROTO_DIR}) 

# Create the target
set(target onnx-parser)
add_executable(${target}  src/main.cpp)


#Add Libs
target_link_libraries(${target} ${LIB_ONNX_DIR}/libonnx_proto.a)
target_link_libraries(${target} ${LIB_PROTO_DIR}/libprotobuf.so)
target_link_libraries(${target} pthread)


