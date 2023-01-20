//
// Created by Jinyuan Zhang on 2023/1/18.
//

#ifndef LEETCODE_ZJY_CMYSTRING_H
#define LEETCODE_ZJY_CMYSTRING_H


class CMyString {
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString operator=(const CMyString& c);
    void Print();
    void Test1();
    void Test2();
    void Test3();

private:
    char *m_pData;
};


#endif //LEETCODE_ZJY_CMYSTRING_H
