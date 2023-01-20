//
// Created by Jinyuan Zhang on 2023/1/19.
//

#include "iostream"
#include <vector>
#include "generateParenthesisSol.h"
#include "set"
using namespace std;

//void generateParenthesisRec(int n, vector<string>& resVec) {
//    if (n == 1) {
//        resVec.push_back("()");
//        return;
//    }
//    vector<string> tempResV;
//    generateParenthesisRec(n-1,tempResV);
//    for (int i = 0; i < tempResV.size(); ++i) {
//    }
//    for (int i = 0; i < tempResV.size(); ++i) {
//        string tempRes = tempResV[i];
//        for (int j = 0; j <= tempRes.size(); ++j) {
//            string tempRes2 = tempRes;
//            tempRes2.insert(j,"(");
//            int tempSize = tempRes2.size();
//            for (int k = j+1; k <= tempSize; ++k) {
//                tempRes2.insert(k,")");
//                resVec.push_back(tempRes2);
//            }
//        }
//    }
//}

void generateParenthesisRec(int n, vector<string>& resVec) {
    if (n == 1) {
        resVec.push_back("()");
        return;
    }
    vector<string> tempResV;
    generateParenthesisRec(n-1,tempResV);
//    for (int i = 0; i < tempResV.size(); ++i) {
//        cout << "temp resv: " << tempResV[i] << endl;
//    }
    for (int i = 0; i < tempResV.size(); ++i) {
        string tempRes = tempResV[i];
        cout << "tempRes: " << tempRes <<"\ti: " << i << endl;
        for (int j = 0; j <= tempRes.size(); ++j) {
            if (j > 0 && tempRes[j-1] == '(') {
                continue;
            }
            string tempRes2 = tempRes;
            tempRes2.insert(j,"(");
            int tempSize = tempRes2.size();
            cout << "tempRes2: " << tempRes2 <<"\tj: " << j << endl;
//            cout << "tempSize: " << tempSize << endl;
            for (int k = j+1; k <= tempSize; ++k) {
                if (k > 0 && tempRes2[k-1] == ')') {
                    continue;
                }
                string tempRes3 = tempRes2;
                tempRes3.insert(k,")");
                cout << "tempRes3: " << tempRes3 <<"\tk: " << k << endl;
                resVec.push_back(tempRes3);
            }
        }
    }
}

bool valid(string str) {
    int balance = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance==0;
}

void generateAll(string &str, int n,vector<string>& resV){
    if (str.size() == 2*n) {
        if (valid(str)) {
            resV.push_back(str);
        }
        return;
    }
    str = str + '(';
    generateAll(str,n,resV);
    str.pop_back();
    str = str + ')';
    generateAll(str, n, resV);
    str.pop_back();
}

void generateValid(string &str, int n, int left, int right, vector<string>& resV){
    if (str.size() == 2 * n) {
        resV.push_back(str);
        return;
    }
    if (left < n) {
        str = str + '(';
        generateValid(str,n,left+1,right,resV);
        str.pop_back();
    }
    if (left > right) {
        str = str + ')';
        generateValid(str,n,left,right+1,resV);
        str.pop_back();
    }
}

vector<string> generateParenthesisSol::generateParenthesis(int n) {
    vector<string> resV;
    if (n == 0) {
        return resV;
    }
    string str = "";
    generateValid(str,n,0,0,resV);
//    generateAll(str,n,resV);
    return resV;
}

int generateParenthesisSol::gMain() {
    int n = 3;
    vector<string> resV = generateParenthesis(n);
    cout << "n = " << n << endl;
//    string str = "()(()";
//    bool v = valid(str);
//    cout << v << endl;
    for (int i = 0; i < resV.size(); ++i) {
        cout << resV[i] << endl;
    }
}