//
// Created by Jinyuan Zhang on 2023/1/16.
//

#include "Palindrome.h"
#include "vector"
using namespace std;
string Palindrome::longestPalindromeDP(string s) {
    int length = s.size();
    string res = "";
    int maxlen = 1;
    int start = 0;
    int newlen = 1;
    if (length < 2) {
        return s;
    }
    vector<vector<int>> dp(length,vector<int>(length));
    for (int i = 0; i < length; ++i) {
        dp[i][i] = true;
    }
    for (int j = 1; j < length; ++j) {
        for (int i = 0; i < j; ++i) {
            if (s[i] != s[j]) {
                dp[i][j] = false;
            } else {
                if (j - i < 3) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            newlen = j-i+1;
            if (dp[i][j] == true && newlen > maxlen) {
                maxlen = newlen;
                start = i;
            }
        }
    }
    return s.substr(start,maxlen);
}

string Palindrome::longestPalindrome(string s) {
    int length = s.size();
    if (length < 2) {
        return s;
    }
    int lenPal = 1;
    int newLenPal = 0;
    string res(1,s[0]);
    int j;
    for (int i = 0; i < length; ++i) {
        for (j = 1; j <= i && i+j < length; j++) {
            if (s[i-j] != s[i+j]) {
                break;
            }
        }
        j--;
        newLenPal = 2 * j + 1;
        if (newLenPal > lenPal) {
            lenPal = newLenPal;
            res = s.substr(i-j,lenPal);
        }
        for (j = 1; j <= i+1 && i+j < length; ++j) {
            if (s[i-j+1] != s[i+j]) {
                break;
            }
        }
        j--;
        newLenPal = 2 * j;
        if (newLenPal > lenPal) {
            lenPal = newLenPal;
            res = s.substr(i-j+1,lenPal);
        }
    }
    return res;
}

bool Palindrome::isPalindrome(string s) {
    int length = s.size();
//    if (length % 2 == 0) {
//        return false;
//    } else {
//        int mid = length/2;
//        for (int i = 1; i <= mid; i++) {
//            if (s[mid + i] != s[mid - i]) {
//                return false;
//            }
//        }
//    }
    int first = 0;
    int last = 0;
    if (length % 2 == 0) {
        last = length/2;
        first = last - 1;
    } else {
        first = length/2 - 1;
        last = first + 2;
    }
    while (first >= 0 && last < length) {
        if (s[first] != s[last]) {
            return false;
        }
        first--;
        last++;
    }
    return true;
}

int Palindrome::pMain() {
//    cout << "Palindrome" << endl;
    string s;
    getline(cin,s);
//    bool res = isPalindrome(s);
    string res = longestPalindromeDP(s);
    cout << "res: " << res << endl;
}