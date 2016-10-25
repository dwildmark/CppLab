//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_OPERATOR_H
#define LAB6_OPERATOR_H

#include "OperationsInterface.h"

class Operator {
private:
    OperationsInterface *opInterface;
public:
    Operator(OperationsInterface *op);
    ~Operator();
    int doOperation(int lhs, int rhs);
    void setOperation(OperationsInterface *op);
};


#endif //LAB6_OPERATOR_H
