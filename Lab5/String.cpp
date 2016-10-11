//
// Created by Dennis Wildmark on 2016-10-07.
//

#include "String.h"

String::String(const String &rhs) {
    capacity = rhs.size() + 20;
    size = rhs.size();
    array = new char [capacity];
    for(int i = 0; i < size; i++) {
        array[i] = rhs[i];
    }
}

String::String(const char* cstr) {

}

String& String::operator=(const String &rhs) {
    String str = String(rhs);
    return str;
}

char& String::operator[](int i) {
    return array[i];
}

const char& String::operator[](int i) const {
    return array[i];
}

int String::size() const {
    return size;
}

int String::capacity() const {
    return capacity;
}

void String::push_back(char c) {
    if(capacity > size) {
        array[size] = c;
        size++;
    } else {
        char* temp = new char[capacity + 1];
        for(int i = 0; i < capacity; i++) {
            temp[i] = array[i];
        }
        temp[capacity] = c;
        delete array;
        array = temp;
        capacity++;
        size++;
    }
}

void operator<<(std::ostream &out, const String &rhs) {

}

const char *String::InternalRep() const {
    return nullptr;
}
