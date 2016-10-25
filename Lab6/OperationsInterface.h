//
// Created by Dennis Wildmark on 2016-10-24.
//

#ifndef LAB6_OPERATIONSINTERFACE_H
#define LAB6_OPERATIONSINTERFACE_H


class OperationsInterface {
public:
    virtual int OperationAdd(int lhs, int rhs) = 0;
    virtual int OperationSubtract(int lhs, int rhs) = 0;
    virtual int OperationMultiply(int lhs, int rhs) = 0;
};


#endif //LAB6_OPERATIONSINTERFACE_H
