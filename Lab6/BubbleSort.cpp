//
// Created by DennisW on 2016-10-25.
//

#include "BubbleSort.h"

void BubbleSort::Sort(std::vector<int> *vector) {
    for(unsigned long i = 0; i < vector->size(); i++) {
        for(unsigned long j = (vector->size() - 1); j > i; j--) {
            if(vector->at(j) < vector->at(j - 1)) {
                int temp = vector->at(j);
                vector->at(j) = vector->at(j - 1);
                vector->at(j - 1) = temp;
            }
        }
    }
}
