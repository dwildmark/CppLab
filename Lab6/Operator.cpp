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
    delete sortInterface;
}

Operator::Operator(OperationsInterface *op, SortAlgInterface *sa) {
    opInterface = op;
    sortInterface = sa;
}

void Operator::setSortAlg(SortAlgInterface *sa) {
    sortInterface = sa;
}

void Operator::doSort(std::vector<int> *vector) {
    sortInterface->Sort(vector);
}

