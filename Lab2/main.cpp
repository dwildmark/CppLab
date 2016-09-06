#include <iostream>
#include <cmath>

void task1(int n);

int main() {
    std::cout << "Starting task 1." << std::endl;
    task1(100);
    return 0;
}

void task1(int n) {
    int list[n - 1];
    for(int i = 0; i < n - 1; i++) {
        list[i] = i + 2;
    }

    for(int i = 0; i < n - 1; i++) {
        if(list[i] % 2 == 0 && list[i] > 2) {
            list[i] = 0;
        }
    }

    int lastPrime = 2;
    while(lastPrime < sqrt(n)) {
        for(auto num : list) {
            if(num != 0 && num > lastPrime) {
                lastPrime = num;
                std::cout << "New prime: " << lastPrime << std::endl;
                break;
            }
        }
        for(int i = lastPrime - 1; i < n - 1; i++) {
            if( list[i] != 0 && list[i]% lastPrime == 0) {
                std::cout << "Deleted non-prime: " << list[i] << std::endl;
                list[i] = 0;
            }
        }
    }
    std::cout << "Result: ";
    for(auto num : list) {
        if(num != 0) {
            std::cout << "[" << num << "]";
        }
    }
    std::cout << std::endl;
}