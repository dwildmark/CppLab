//
// Created by Dennis Wildmark on 2016-10-07.
//

#ifndef LAB5_STRING_H
#define LAB5_STRING_H


class String {
public:
    String(const String& rhs);
    String(const char* cstr);

    String& operator = (const String& rhs);
    char& operator[](int i);
    const char& operator[](int i) const;
    int size() const;
    int capacity() const;
    void push_back(char c);
    friend bool operator == (const String& lhs, const String& rhs);
    operator << ()

};


#endif //LAB5_STRING_H
