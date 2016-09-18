//
// Created by Dennis Wildmark on 2016-09-14.
//

#include "PersonReg.h"
#include <iostream>

PersonReg::PersonReg(int maxSize): maxSize(maxSize) {
    persons = new Person[maxSize]();
    size = 0;
}

int PersonReg::addPerson(Person *p_person) {
    if(size < maxSize) {
        persons[size] = *p_person;
        size++;
        return 0;
    }
    return -1;
}

void PersonReg::removePerson(Person *p_person) {
    for(int i = 0; i < size; i++) {
        if(&persons[i] == p_person) {
            for(int j = i; j < size - 1; j++) {
                persons[j] = persons[j + 1];
            }
            size--;
            break;
        }
    }
}

Person *PersonReg::findPerson(std::string name) {
    for(int i = 0; i < size; i++) {
        if(!persons[i].name.compare(name)) {
            return &(persons[i]);
        }
    }
    return nullptr;
}

void PersonReg::print() {
    for(int i = 0; i < size; i++) {
        persons[i].print();
    }
}

PersonReg::~PersonReg() {
    delete[] persons;
}

