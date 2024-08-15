cmake_minimum_required(VERSION 3.9)
project(callFunc_try)

#设定编译参数
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
 
#生成可执行文件
add_executable(myCpp main.cpp )

find_package(Python3 3.12.4 COMPONENTS Interpreter Development REQUIRED)
if (Python3_FOUND)
    message("Python include directory: " ${Python3_INCLUDE_DIRS})
    message("Python version is: " ${Python3_VERSION})
    message(${Python3_LIBRARIES})
endif (Python3_FOUND)

include_directories(../pythonLib/include/python3.12)
target_link_libraries(myCpp /home/lrx/codes/Cpp-call-Python-Demo/pythonLib/lib/libpython3.12.so.1.0)
