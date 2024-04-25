cmake_minimum_required(VERSION 3.9)
project(callFunc_try)
 
 
#设定编译参数
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
 
#设定源码列表.cpp
# set(SOURCE_FILES ./main.cpp)
#设定所有源码列表 ：aux_source_directory(<dir> <variable>)
#比如:aux_source_directory(${CMAKE_SOURCE_DIR} DIR)  将${CMAKE_SOURCE_DIR}目录下，也就是最顶级目录下所有的.cpp文件放入DIR变量中，后面的add_executable就可以很简化
#    add_executable(hello_world ${DIR})
 
 
#设定头文件路径
# include_directories(../pythonLib/include/python3.10)

# "../pythonLib/Headers/cpython" "../pythonLib/Headers/internal"

#include_directories("路径1"  “路径2”...)
 
 
#设定链接库的路径（一般使用第三方非系统目录下的库）
# link_directories(../pythonLib/lib)
#link_directories("路径1"  “路径2”...)
 
 
#添加子目录,作用相当于进入子目录里面，展开子目录的CMakeLists.txt
#同时执行，子目录中的CMakeLists.txt一般是编译成一个库，作为一个模块
#在父目录中可以直接引用子目录生成的库
#add_subdirectory(math)
 
 
#生成动/静态库
#add_library(动/静态链接库名称  SHARED/STATIC(可选，默认STATIC)  源码列表)
#可以单独生成多个模块
 
 
#生成可执行文件
add_executable(myCpp main.cpp )
#比如：add_executable(hello_world    ${SOURCE_FILES})


find_package(Python3 3.10 COMPONENTS Interpreter Development REQUIRED)
if (Python3_FOUND)
    message("Python include directory: " ${Python3_INCLUDE_DIRS})
    message("Python version is: " ${Python3_VERSION})
    message(${Python3_LIBRARIES})
endif (Python3_FOUND)

include_directories(../pythonLib/include/python3.12)
# target_link_libraries(myCpp ${Python3_LIBRARIES})
# target_link_libraries(myCpp ../pythonLib/lib)
target_link_libraries(myCpp /Users/kevinyu/Desktop/BXC_CppCallPython/pythonLib/lib/libpython3.12.dylib)
# target_link_libraries(myCpp libpython3.10.dylib)  #就是g++ 编译选项中-l后的内容，不要有多余空格
 
# ADD_CUSTOM_COMMAND( #执行shell命令
#          TARGET myCpp
#          POST_BUILD #在目标文件myLevelDBbuild之后，执行下面的拷贝命令，还可以选择PRE_BUILD命令将会在其他依赖项执行前执行  PRE_LINK命令将会在其他依赖项执行完后执行  POST_BUILD命令将会在目标构建完后执行。
#          COMMAND cp ./myCpp  ../
#         #  COMMAND ../myCpp
# ) 
