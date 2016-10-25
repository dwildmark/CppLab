#include <iostream>
#include "Add.h"
#include "Operator.h"
#include "Subtract.h"
#include "Multiply.h"

int main() {
    Add *add = new Add();
    Subtract *subtract = new Subtract();
    Multiply *multiply = new Multiply();
    Operator *op = new Operator(add);
    int result = op->doOperation(5, 4);
    std::cout << "5 + 4 = " << result << std::endl;
    op->setOperation(subtract);
    result = op->doOperation(5, 4);
    std::cout << "5 - 4 = " << result << std::endl;
    op->setOperation(multiply);
    result = op->doOperation(5, 4);
    std::cout << "5 * 4 = " << result << std::endl;
    return 0;
}