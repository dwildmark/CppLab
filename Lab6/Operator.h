//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_OPERATOR_H
#define LAB6_OPERATOR_H

#include "OperationsInterface.h"
#include "SortAlgInterface.h"

class Operator {
private:
    OperationsInterface *opInterface;
    SortAlgInterface *sortInterface;
public:
    Operator(OperationsInterface *op, SortAlgInterface *sa);
    ~Operator();
    int doOperation(int lhs, int rhs);
    void doSort(std::vector<int> *vector);
    void setOperation(OperationsInterface *op);
    void setSortAlg(SortAlgInterface *sa);
};


#endif //LAB6_OPERATOR_H
