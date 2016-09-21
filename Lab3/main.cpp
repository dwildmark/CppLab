#include <iostream>
#include <fstream>
#include "Person.h"
#include "PersonReg.h"
#include "PersonMedTel.h"

using namespace std;

bool ReadReg(PersonReg& reg, string fileName);

int main() {

    PersonReg *p_personreg = new PersonReg(6);
    ReadReg(*p_personreg, "/Users/dennisw/CppLab/Lab3/PersonExempel.txt");

    p_personreg->print();

    Person* x1 = p_personreg->find("sson", nullptr); //x1 blir första träffen
    Person* x2 = p_personreg->find("sson", x1); //x2 blir andra träffen
    Person* x3 = p_personreg->find("sson", x2);
    x1->print();
    x2->print();
    x3->print();

    delete p_personreg;
    p_personreg = new PersonReg(5);
    Person * myPerson = new PersonMedTel("Dennis", "Rönnblomsgatan 11 lgh 1228 21216 MALMÖ", "0721577226");
    myPerson->print(); //Om Print är virtual i Person så anropas PersonMedTel::Print
    p_personreg->addPerson(myPerson);
    p_personreg->print();
    delete p_personreg;
    return 0;
}

bool ReadReg(PersonReg& reg, string fileName) {
    string line;
    ifstream myfile;
    myfile.open((fileName), ifstream::in);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            while (line.length() == 0 && getline(myfile, line));
            string name(line);
            string adress;
            getline(myfile, adress);
            reg.addPerson(new Person(name, adress));
        }
        myfile.close();
        return true;
    }
    else {
        cout << "Unable to open file";
        return false;
    }
}