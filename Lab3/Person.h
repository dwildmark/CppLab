//
// Created by Dennis Wildmark on 2016-09-14.
//

#ifndef LAB3_PERSON_H
#define LAB3_PERSON_H
#include <string>
using std::string;

class Person {
public:
    Person(string name, string adress);
    Person();
    string name;
    string adress;
    virtual void print();
    bool compare(Person* person);
};


#endif //LAB3_PERSON_H
