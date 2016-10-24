//
// Created by Dennis Wildmark on 2016-10-07.
//

#ifndef LAB5_STRING_H
#define LAB5_STRING_H


#include <iosfwd>
#include <cstring>
#include <iostream>

class String {
private:
    char* mArray;
    int mCapacity;
    int mSize;
public:
    ~String();
    String();
    String(const String& rhs);
    String(const char* cstr);

    String& operator = (const String& rhs);
    char& operator[](int i);
    const char& operator[](int i) const;
    int size() const;
    int capacity() const;
    void push_back(char c);
    friend bool operator == (const String& lhs, const String& rhs);
    const char* InternalRep() const;
    friend std::ostream& operator << (std::ostream& out, const String& rhs);
};
#endif //LAB5_STRING_H
