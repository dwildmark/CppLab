//
// Created by Dennis Wildmark on 2016-10-07.
//

#include "String.h"

String::String(const String &rhs) {
    mSize = rhs.size();
    mCapacity = mSize;
    mArray = new char[mCapacity];
    for(int i = 0; i < mSize; i++) {
        mArray[i] = rhs[i];
    }
}

String::String(const char* cstr) {
    mSize = (int)strlen(cstr);
    mCapacity = mSize;
    mArray = new char[mCapacity];
    for(int i = 0; i < mSize; i++) {
        mArray[i] = cstr[i];
    }
}

String& String::operator=(const String &rhs) {
    if(this == &rhs) {
        return *this;
    }
    delete[] mArray;
    mSize = rhs.size();
    mCapacity = mSize + 20;
    mArray = new char[mCapacity];
    for(int i = 0; i < mSize; i++) {
        mArray[i] = rhs[i];
    }
    return *this;
}

char& String::operator[](int i) {
    return mArray[i];
}

const char& String::operator[](int i) const {
    return mArray[i];
}

int String::size() const {
    return mSize;
}

int String::capacity() const {
    return mCapacity;
}

void String::push_back(char c) {
    if(mCapacity > mSize) {
        mArray[mSize] = c;
        mSize++;
    } else {
        char* temp = new char[mCapacity + 1];
        for(int i = 0; i < mCapacity; i++) {
            temp[i] = mArray[i];
        }
        temp[mCapacity] = c;
        delete[] mArray;
        mArray = temp;
        mCapacity++;
        mSize++;
    }
}

const char* String::InternalRep() const {
    return mArray;
}

bool operator==(const String &lhs, const String &rhs) {
    if(lhs.size() == rhs.size()) {
        for(int i = 0; i < lhs.size(); i++) {
            if(lhs[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

String::String() {
    mArray = {};
    mCapacity = 0;
    mSize = 0;
}

String::~String() {
    delete[] mArray;
}

std::ostream& operator<< (std::ostream& out, const String& rhs) {
    for (int i=0; i<rhs.size();++i)
        out << rhs[i];
    return out;
}
