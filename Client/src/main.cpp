#include "include/python.h"
#include "game.h"
#include "map.h"
#include "network.h"

#include <iostream>

int main(){


    Py::Start();

    Py::Set("mama", "lol");

    Py::Run("mama = 'nope'");

    std::string value;
    Py::Get("mama",value);
    std::cout<<value;

    Py::Stop();



    return 0;
}
