#include <iostream>
#include <cmath>
#include <string.h>

void task1(int n);
void task2();
void task3();
void Substitute2(std::string& iostring,
                 const std::string& before,
                 const std::string& after);
char* Substitute3(char* const input,
                  const char before,
                  char* const after);


int main() {
    int a;
    std::cout << "Which task do you want to run?" << std::endl;
    std::cin >> a;
    switch(a) {
        case 1:
            std::cout << "Starting task 1." << std::endl;
            task1(100);
            break;
        case 2:
            std::cout << "Starting task 2." << std::endl;
            task2();
            break;
        case 3:
            std::cout << "Starting task 3." << std::endl;
            task3();
            break;
        case 4:
            std::cout << "Starting task 4." << std::endl;
            break;
    }

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

void task2() {
    std::string input = "Hejjj";
    Substitute2(input, "ej", "eje");
    std::cout << input << std::endl;
}

void task3() {
    Substitute3("bbbabbbabbbabbb", 'a', "REP");
}

void Substitute2(std::string& iostring,
                 const std::string& before,
                 const std::string& after) {
    int index = (int)iostring.find(before);
    std::string res = iostring.substr(0, index) + after + iostring.substr(index + before.length());
    iostring = res;
}

char* Substitute3(char* const input, const char before, char* const after) {
    int indexes[strlen(input)];
    int indexc = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == before) {
            indexes[indexc] = i;
            indexc++;
        }
    }
    int newlength = strlen(input) + (indexc * (strlen(after) - 1)) + 1;
    char output[newlength];
    int lastindex = 0;
    int inptindex = 0;
    for(int i = 0; i < indexc; i++) {
        int replaceindex = indexes[i] + (i * (strlen(after) - 1));
        for(int j = lastindex; j < replaceindex; j++) {
            output[j] = input[inptindex];
            inptindex++;
        }
        for(int j = 0 ; j < strlen(after); j++) {
            output[j + replaceindex] = after[j];
        }
        lastindex = replaceindex + strlen(after);
        inptindex++;
    }
    if(lastindex < newlength - 1){
        for(int j = lastindex; j < newlength - 1; j++) {
            output[j] = input[inptindex];
            inptindex++;
        }
    }
    output[newlength - 1] = '\0';
    std::cout << "Input: " << input << std::endl;
    std::cout << "Replace " << before << " with " << after << std::endl;
    std::cout << output << std::endl;
}