///   example

//    Py::Start();
//
//    Py::Set("x", "lol");
//
//    Py::Run("x = 'nope'");
//
//    std::string y;
//    Py::Get("x",y);
//    //y now has the value of x
//
//    Py::Stop();

#ifndef PYTHON_H
#define PYTHON_H

#include "python/Python.h"
#include <string>
#include <iostream>

namespace Py{
    //some objects
    PyObject* main;
    PyObject* global;
    PyObject* local;

    //start and stop functions
    void Start(){
        Py_Initialize();
        main = PyImport_AddModule("__main__");
        global = PyModule_GetDict(main);
        local = PyDict_New();
    }
    void Stop(){
        Py_Finalize();
    }
    //run a simple string script, given the current local variables, returns 0 on success
    int Run(std::string s){
        if(PyRun_String(s.c_str(), Py_file_input, global, local)){
            return 0;
        }else{
            return 1;
        }
    }

    //set local variables
    template <typename T>
    void Set(std::string s, T t);
    template<>
    void Set(std::string s, int x){
        PyDict_SetItemString(local, s.c_str(), PyInt_FromLong(x));
    }
    template<>
    void Set(std::string s, double x){
        PyDict_SetItemString(local, s.c_str(), PyFloat_FromDouble(x));
    }
    template<>
    void Set(std::string s, std::string x){
        PyDict_SetItemString(local, s.c_str(), PyString_FromString(x.c_str()));
    }
    template<>
    void Set(std::string s, char const* x){
        PyDict_SetItemString(local, s.c_str(), PyString_FromString(x));
    }


    //get local variables
    template <typename T>
    void Get(std::string s, T& t);
    template<>
    void Get(std::string s, int& x){
        x = PyInt_AsLong(PyDict_GetItemString(local, s.c_str()));
    }
    template<>
    void Get(std::string s, double& x){
        x = PyFloat_AsDouble(PyDict_GetItemString(local, s.c_str()));
    }
    template<>
    void Get(std::string s, std::string& x){
        x = PyString_AsString(PyDict_GetItemString(local, s.c_str()));
    }
};

#endif // PYTHON_H
