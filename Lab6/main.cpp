#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
#include "Add.h"
#include "Operator.h"
#include "Subtract.h"
#include "Multiply.h"
#include "BubbleSort.h"
#include "StdSort.h"

std::ostream& operator <<(std::ostream& out, std::vector<int> vec);
void fillVector(std::vector<int>& vec);

int main() {
    Add *add = new Add();
    Subtract *subtract = new Subtract();
    Multiply *multiply = new Multiply();
    BubbleSort *bubbleSort = new BubbleSort();
    StdSort *stdSort = new StdSort();
    Operator *op = new Operator(add, stdSort);

    std::cout << "<---------Test of operations-------->" << std::endl;
    int result = op->doOperation(5, 4);
    std::cout << "5 + 4 = " << result << std::endl;
    op->setOperation(subtract);
    result = op->doOperation(5, 4);
    std::cout << "5 - 4 = " << result << std::endl;
    op->setOperation(multiply);
    result = op->doOperation(5, 4);
    std::cout << "5 * 4 = " << result << std::endl;

    std::cout << "<---------Test of std::sort-------->" << std::endl;
    std::vector<int> vector(10);
    fillVector(vector);
    op->setSortAlg(stdSort);
    std::cout << "Array before: " << vector << std::endl;
    op->doSort(&vector);
    std::cout << "Sorting with std::sort..." << std::endl;
    std::cout << "Array after: " << vector << std::endl;

    std::cout << "<---------Test of Bubblesort-------->" << std::endl;
    fillVector(vector);
    op->setSortAlg(bubbleSort);
    std::cout << "Array before: " << vector << std::endl;
    op->doSort(&vector);
    std::cout << "Sorting with Bubblesort..." << std::endl;
    std::cout << "Array after: " << vector << std::endl;
    return 0;
}

std::ostream& operator <<(std::ostream& out, std::vector<int> vec) {
    for (auto i : vec) {
        std::cout << i << " ";
    }
    return out;
}

void fillVector(std::vector<int>& vec){
    std::random_device rnd_device;
    std::mt19937 mersenne_engine(rnd_device());
    std::uniform_int_distribution<int> dist(1, 20);
    auto gen = std::bind(dist, mersenne_engine);
    generate(begin(vec), end(vec), gen);
}