//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_ADD_H
#define LAB6_ADD_H


#include "OperationsInterface.h"

class Add : public OperationsInterface{
public:
    int Operation(int lhs, int rhs);
};


#endif //LAB6_ADD_H
