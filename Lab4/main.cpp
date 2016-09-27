#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include "PersonReg.h"
#include "Person.h"

void task1a();
void task1b();
void task1c();
void task1d();
bool Greater(int a, int b);
void task2a();

int main() {
    std::cout << "Choose task: " << std::endl;
    int input;
    std::cin >> input;
    switch(input)
    {
        case 1:
            task1a();
            break;
        case 2:
            task1b();
            break;
        case 3:
            task1c();
            break;
        case 4:
            task1d();
            break;
        case 5:
            task2a();
            break;
        default:
            break;
    }
    return 0;
}

void task1a() {
    std::vector<int> v = std::vector<int>(10);
    iota(v.begin(), v.end(), 4);
    random_shuffle(v.begin(), v.end());
    std::cout << "---------Shuffled---------" << std::endl;
    for(auto x : v) {
        std::cout << "[" << x << "]";
    }
    std::cout << std::endl;
    std::cout << "----------Sorted----------" << std::endl;
    sort(v.begin(), v.end());
    for(auto x : v) {
        std::cout << "[" << x << "]";
    }
    std::cout << std::endl;
}

void task1b() {
    int arr [10];
    std::cout << "---------Shuffled---------" << std::endl;
    for(auto &elem : arr) {
        elem = rand();
        std::cout << "[" << elem << "]";
    }
    std::cout << std::endl;
    std::sort(std::begin(arr), std::end(arr));
    std::cout << "----------Sorted----------" << std::endl;
    for(auto &elem : arr) {
        std::cout << "[" << elem << "]";
    }
    std::cout << std::endl;
}

void task1c() {
    std::vector<int> v = std::vector<int>(10);
    iota(v.begin(), v.end(), 4);
    random_shuffle(v.begin(), v.end());
    std::cout << "---------Shuffled---------" << std::endl;
    for(auto x : v) {
        std::cout << "[" << x << "]";
    }
    std::cout << std::endl;
    std::cout << "----------Sorted----------" << std::endl;
    sort(v.rbegin(), v.rend());
    for(auto x : v) {
        std::cout << "[" << x << "]";
    }
    std::cout << std::endl;
}

void task1d() {
    int arr [10];
    std::cout << "---------Shuffled---------" << std::endl;
    for(auto &elem : arr) {
        elem = rand();
        std::cout << "[" << elem << "]";
    }
    std::cout << std::endl;

    std::sort(std::begin(arr), std::end(arr), Greater);

    std::cout << "----------Sorted----------" << std::endl;
    for(auto &elem : arr) {
        std::cout << "[" << elem << "]";
    }
    std::cout << std::endl;
}

void task2a() {
    PersonReg p(6);
    p.addPerson( new Person("Dennis", "Sjobo"));
    p.addPerson( new Person("Dennis", "Malme"));
    p.addPerson( new Person("Jonath", "Helsingburg"));
    p.addPerson( new Person("Jonath", "MINC"));
    p.addPerson( new Person("John", "Vetifan"));
    std::random_shuffle(p.begin(), p.end());
    p.print();
    //std::sort(p.begin(), p.end());
    p.print();
}

bool Greater(int a, int b) {
    return a>b;
}