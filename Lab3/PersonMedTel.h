//
// Created by Dennis Wildmark on 2016-09-19.
//

#ifndef LAB3_PERSONMEDTEL_H
#define LAB3_PERSONMEDTEL_H


#include "Person.h"

class PersonMedTel: public Person {
public:
    PersonMedTel(std::string name, std::string adress, std::string tel);
    std::string nummer;
    void print() override ;
};


#endif //LAB3_PERSONMEDTEL_H
