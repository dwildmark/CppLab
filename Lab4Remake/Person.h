//
// Created by Dennis Wildmark on 2016-09-14.
//

#ifndef LAB4REMAKE_PERSON_H
#define LAB4REMAKE_PERSON_H
#include <string>

using std::string;

class Person {
public:
    Person(const std::string name, const std::string adress);
    Person();
    string name;
    string adress;
    virtual void print();
    bool compare(Person* person);
    bool operator<(const Person& that) const;
};


#endif //LAB3_PERSON_H
