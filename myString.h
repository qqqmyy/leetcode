//
// Created by Jinyuan Zhang on 2023/3/31.
//

#ifndef LEETCODE_ZJY_MYSTRING_H
#define LEETCODE_ZJY_MYSTRING_H


class myString {
private:
    char *str;
    int len;

public:
    myString(const char* s);
    myString();
    myString(const myString &);
    ~myString();

    int length();
    int size();

    myString &operator+(const myString &st);
    myString &operator+(const char *s);

    void push_back(const char *ch);
    void print();
};


#endif //LEETCODE_ZJY_MYSTRING_H
