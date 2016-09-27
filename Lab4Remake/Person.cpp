//
// Created by Dennis Wildmark on 2016-09-14.
//

#include "Person.h"
#include <iostream>
using std::string;

#define COMPARE_BY_NAME 1

Person::Person(const std::string name, const std::string adress) {
    this->name = name;
    this->adress = adress;
}

Person::Person() {

}

void Person::print() {
    if(!(name.empty()) && !(adress).empty()) {
        std::cout << "Name: " << name << " Adress: " << adress << std::endl;
    }
}

bool Person::compare(Person* person) {
    if(!(name.empty()) && !(adress).empty()) {
        return (!(this->name.compare(person->name)) && !(this->adress.compare(person->adress)));
    }
    return false;
}

bool Person::operator<(const Person& that) {
#if COMPARE_BY_NAME
    return this->name < that.name;
#else
    return this->adress > that.adress;
#endif
}