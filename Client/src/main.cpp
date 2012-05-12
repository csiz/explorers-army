#include "include/python.h"
#include "game.h"
#include "map.h"
#include "network.h"

#include <iostream>

int main(){


    Py::Start();

    Py::Set("id", "csiz");
    Py::Set("password", "abc");
    Py::Set("name", "calin");


    Py::Run("import python.user");
    Py::Run("status = python.user.status()");
    std::string status;
    Py::Get("status", status);
    std::cout<<status<<std::endl;

    Py::Run("response = python.user.information(id,password)");


    std::string response;
    Py::Get("response",response);
    std::cout<<response;

    Py::Stop();



    return 0;
}
