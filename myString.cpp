//
// Created by Jinyuan Zhang on 2023/3/31.
//

#include "myString.h"
#include "iostream"
#include "stdlib.h"
#include "string.h"

using namespace std;

myString::myString() {
    len = 1;
    str = new char[len+1];
    str[0] = '\0';
}

myString::myString(const char *s) {
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
}

myString::myString(const myString &st) {
    len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
}

myString::~myString() {
    delete [] str;
}

void myString::print() {
    cout << str << endl;
}

void myString::push_back(const char *ch) {
    cout << "len = " << strlen(str) << endl;
    strcat(this->str, ch);
    cout << "len = " << strlen(str) << endl;
    len++;
    cout << "len = " << len << endl;
    return;
}

