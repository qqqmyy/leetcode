//
// Created by Jinyuan Zhang on 2023/2/28.
//

#ifndef LEETCODE_ZJY_MERGESOL_H
#define LEETCODE_ZJY_MERGESOL_H

#include "vector"
using namespace std;


class mergeSol {
public:
    static bool greaterSort(vector<int>& x, vector<int>& y);
    vector<vector<int>> merge(vector<vector<int>>& intervals);
    int mMain();
};


#endif //LEETCODE_ZJY_MERGESOL_H
