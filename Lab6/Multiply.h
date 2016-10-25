//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_MULTIPLY_H
#define LAB6_MULTIPLY_H


#include "OperationsInterface.h"

class Multiply : public OperationsInterface{
public:
    int Operation(int lhs, int rhs);
};


#endif //LAB6_MULTIPLY_H
