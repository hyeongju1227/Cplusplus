/***** String.h *****/

#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
using namespace std;

class string{
    int len;
    char* str;
public:
    string(const char* s=NULL);
    string(const string& s);
    ~string();
    string& operator=(const string& s);
    string& operator+=(const string& s);
    bool operator==(const string& s);
    string operator+(const string& s);

    friend ostream& operator<<(ostream& os, const string& s);
    friend istream& operator>>(istream& is, string& s);
};

#endif