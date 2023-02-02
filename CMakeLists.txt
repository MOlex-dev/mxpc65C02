cmake_minimum_required(VERSION 3.23)
project(mxpc65C02)

set(CMAKE_CXX_STANDARD 23)

add_executable(mxpc65C02 src/main.cpp include/util.hpp src/util.cpp include/frequency.hpp src/frequency.cpp include/memory.hpp src/memory.cpp include/exceptions/mxpc_exception.hpp src/exceptions/mxpc_exception.cpp include/exceptions/memory_exception.hpp src/exceptions/memory_exception.cpp include/settings.hpp src/settings.cpp include/exceptions/cmd_exception.hpp src/exceptions/cmd_exception.cpp)
