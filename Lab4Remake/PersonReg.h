//
// Created by Dennis Wildmark on 2016-09-14.
//

#ifndef LAB4REMAKE_PERSONREG_H
#define LAB4REMAKE_PERSONREG_H
#include "Person.h"
#include <string>

class PersonReg {
private:
    Person *persons;
    const int maxSize;
    int size;
public:
    PersonReg(int maxSize);
    int addPerson(Person *p_person);
    void removePerson(Person *p_person);
    Person* findPerson(std::string name);
    Person* find(string search, Person* person);
    void print();
    ~PersonReg();
    Person* begin();
    Person* end();
};


#endif //LAB3_PERSONREG_H
