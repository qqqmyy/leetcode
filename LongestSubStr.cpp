//
// Created by Jinyuan Zhang on 2023/1/14.
//

#include <unordered_set>
#include "LongestSubStr.h"
#include "iostream"

using namespace std;

int LongestSubStr::lengthOfLongestSubstring(string s){
//    std::cout<<s<<std::endl;
    unordered_set<char> appStr;
    int length = s.size();
    int rk = 0;
    int res = 0;
//    cout << length << endl;
    for (int i = 0; i < length; i++) {
        while (rk < length && (appStr.count(s[rk]) == 0)) {
            appStr.insert(s[rk]);
            rk++;
        }
        res = max(res,rk-i);
        appStr.erase(s[i]);
    }
    return res;
}

int LongestSubStr::LongestSubStrMain() {
    string str;
    getline(cin,str);
    int res = lengthOfLongestSubstring(str);
    cout << res << endl;
}