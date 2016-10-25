//
// Created by DennisW on 2016-10-25.
//

#ifndef LAB6_SORTALGINTERFACE_H
#define LAB6_SORTALGINTERFACE_H


#include <vector>

class SortAlgInterface {
public:
    virtual void Sort(std::vector<int> *vector) = 0;
};


#endif //LAB6_SORTALGINTERFACE_H
