//
// Created by Dennis Wildmark on 2016-09-14.
//

#include "Person.h"
#include <iostream>

Person::Person(string name, string adress) {
    this->name = name;
    this->adress = adress;
}

Person::Person() {

}

void Person::print() {
    std::cout << "Name: " << name << " Adress: " << adress << std::endl;
}