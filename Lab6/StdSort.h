//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_STDSORT_H
#define LAB6_STDSORT_H


#include "SortAlgInterface.h"

class StdSort : public SortAlgInterface{
public:
    void Sort(std::vector<int> *vector);
};


#endif //LAB6_STDSORT_H
