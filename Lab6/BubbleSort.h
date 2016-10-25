//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_BUBBLESORT_H
#define LAB6_BUBBLESORT_H


#include "SortAlgInterface.h"

class BubbleSort : public SortAlgInterface{
public:
    void Sort(std::vector<int> *vector);
};


#endif //LAB6_BUBBLESORT_H
