#include <iostream>
#include "Person.h"
#include "PersonReg.h"

int main() {

    Person *p1 = new Person("Dennis", "Ronnen");
    Person *p2 = new Person("Lang", "Myllan");
    Person *p3 = new Person("Tengvall", "Kronis");

    PersonReg *p_personreg = new PersonReg(3);

    p_personreg->addPerson(p1);
    p_personreg->addPerson(p2);
    p_personreg->addPerson(p3);
    p_personreg->print();
    p_personreg->removePerson(p_personreg->findPerson("Dennis"));
    p_personreg->print();
    p_personreg->removePerson(p_personreg->findPerson("Tengvall"));
    p_personreg->print();

    delete p1;
    delete p2;
    delete p3;
    delete p_personreg;
    return 0;
}