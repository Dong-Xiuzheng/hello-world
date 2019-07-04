# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (fork_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# 指定生成目标
add_executable(server server.cpp)
add_executable(client client.cpp)
add_executable(execv execv.cpp)

