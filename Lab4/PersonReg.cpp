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
        delete p_person;
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

Person* PersonReg::findPerson(std::string name) {
    for(int i = 0; i < size; i++) {
        if(!persons[i].name.compare(name)) {
            return &(persons[i]);
        }
    }
    return nullptr;
}

Person* PersonReg::find(string search, Person* person) {
    int index = 0;
    if(person != nullptr) {
        for(int i = 0; i < size; i++) {
            if(persons[i].compare(person)) {
                index = i;
            }
        }
    }
    for(int i = index + 1; i < size; i++) {
        if(persons[i].name.find(search) != std::string::npos
           || persons[i].adress.find(search) != std::string::npos ){
            return &persons[i];
        }
    }
    return nullptr;
}

void PersonReg::print() {
    std::cout << "--------REGISTER--------" << std::endl;
    for(int i = 0; i < size; i++) {
        persons[i].print();
    }
    std::cout << "----------END----------" << std::endl;

}

PersonReg::~PersonReg() {
    delete[] persons;
}

Person* PersonReg::begin() {
    return persons;
}

Person* PersonReg::end() {
    return persons + size;
}

