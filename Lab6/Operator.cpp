//
// Created by DennisW on 2016-10-25.
//

#include "Operator.h"

int Operator::doOperation(int lhs, int rhs) {
    return opInterface->Operation(lhs, rhs);
}

void Operator::setOperation(OperationsInterface *op) {
    opInterface = op;
}

Operator::~Operator() {
    delete opInterface;
}

Operator::Operator(OperationsInterface *op) {
    opInterface = op;
}

