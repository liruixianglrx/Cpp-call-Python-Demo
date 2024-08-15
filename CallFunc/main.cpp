#include <Python.h>
#include <iostream>

using namespace std;

void test()
{   
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/lrx/codes/Cpp-call-Python-Demo/CallFunc')");

    PyObject* pModule = NULL;
    PyObject* pFunc = NULL;
    PyObject* pArg = NULL;
    pModule = PyImport_ImportModule("py_CallFunc"); 

    pFunc = PyObject_GetAttrString(pModule, "Hello");
    pArg = Py_BuildValue("(s)", "c++ is the test!"); 
    PyObject_Call(pFunc, pArg, NULL);

    Py_Finalize();
}

int main() {

    test();

    return 0;
}

