//
// Created by Laura Kristina on 07.06.16.
//

#include "newlib.h"


newlib::newlib() {
    ID = 42;
}

int newlib::getID(){
    return ID;
}

std::string newlib::getIDtxt() {
    return "beautiful 42";
}

