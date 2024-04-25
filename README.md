# Cpp-Call-Python-Demo

`CallFunc/`: Includes main cpp script, CMakeList and python function. 

`pythonLib/`: includes necessary dependencies you need to run python server. 

## Notes for main.cpp

In main.cpp, the first three lines in test() creates a python instance and initialize the required path. *you will need to change the 'sys.path.append' element to your own path*.

```
PyRun_SimpleString("importsys");
PyRun_SimpleString("sys.path.append('/Users/kevinyu/Desktop/BXC_CppCallPython/CallFunc')");
```

## Notes for CMakeLists.txt

The "find_package" instruction in CMakeLists prints out your python install path on your system.  

You should change "include_directories" and "target_link_libraries" to your own system path. 

