//
// Created by Jinyuan Zhang on 2023/1/18.
//

#include "LetterCombinationsSol.h"
#include "string"
#include "vector"
#include "map"
using namespace std;

void solver(string digits, vector<string>& resV, map<char,string>& phoneMap) {
    if (digits.size() == 0) {
        resV.push_back("");
        return;
    }
    char cur = digits[0];
    digits.erase(0,1);

    vector<string> partRes;
    solver(digits,partRes,phoneMap);
    string curStr = phoneMap[cur];
    for (int i = 0; i < curStr.size(); ++i) {
        char curChar = curStr[i];
        for (int j = 0; j < partRes.size(); ++j) {
            resV.push_back(curChar+partRes[j]);
        }
    }
    return;
}

vector<string> solverRec(string digits, map<char,string>& phoneMap) {
    vector<string> resV;
    if (digits.size() == 0) {
        resV.push_back("");
        return resV;
    }
    char ch = digits[0];
    digits.erase(0,1);
    vector childResV = solverRec(digits,phoneMap);
    string str = phoneMap[ch];
    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < childResV.size(); ++j) {
            resV.push_back(str[i] + childResV[j]);
        }
    }
    return resV;
}

//void solver(string digits, vector<string>& resV, map<char,string>& phoneMap) {
//    if (digits.size() == 0) {
//        resV.push_back("");
//        return;
//    }
//    char cur = digits[0];
//    cout << "cur: " << cur << endl;
//    digits.erase(0,1);
//
//    cout << "digits: " << digits << endl;
//
//    vector<string> partRes;
//    solver(digits,partRes,phoneMap);
//    string curStr = phoneMap[cur];
//    cout << "curStr: " << curStr << endl;
//    cout << "curStr.size(): " << curStr.size() << endl;
//    for (int i = 0; i < curStr.size(); ++i) {
//        char curChar = curStr[i];
//        cout << "curChar: " << curChar << endl;
//        cout << "resV.size(): " << resV.size() << endl;
//        cout << "curChar+partRes[j]: " << curChar+partRes[0] << endl;
//        for (int j = 0; j < partRes.size(); ++j) {
////            cout << "curChar+resV[j]: " << curChar+resV[j] << endl;
//            resV.push_back(curChar+partRes[j]);
//        }
//        cout << "end" <<endl;
//    }
//    return;
//}

void backtrack(vector<string>& combinations, const map<char, string>& phoneMap, const string& digits, int index, string& combination) {
    if (index == digits.length()) {
        combinations.push_back(combination);
    } else {
        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        for (const char& letter: letters) {
            combination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
}

vector<string> LetterCombinationsSol::letterCombinations(string digits) {
    vector<string> resV;
    if (digits.size() == 0) {
        return resV;
    }
    map<char,string> phoneMap {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
    };
    resV = solverRec(digits,phoneMap);
//    solver(digits,resV,phoneMap);
//    string combination;
//    backtrack(resV, phoneMap, digits, 0, combination);
    return resV;
}

int LetterCombinationsSol::lMain() {
    string digits = "23";
//    getline(cin,digits);
    cout << digits << endl;
    vector<string> res = letterCombinations(digits);
    for (int i = 0; i < res.size(); ++i) {
       cout << res[i] << "\t";
    }
}