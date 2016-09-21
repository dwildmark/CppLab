#include <iostream>

int main() {
    int a = 0x1;
    for(int i = 0; i < 100; i++) {
        a = !a;
        std::cout << a << std::endl;
    }
    return 0;
}