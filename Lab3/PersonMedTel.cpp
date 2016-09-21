//
// Created by Dennis Wildmark on 2016-09-19.
//

#include <iostream>
#include "PersonMedTel.h"

PersonMedTel::PersonMedTel(std::string name, std::string adress, std::string tel): Person(name, adress) {
    nummer = tel;
}

void PersonMedTel::print() {
    std::cout << "Name: " << name << " Adress: " << adress << " Number: " << nummer << std::endl;
}
