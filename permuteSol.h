//
// Created by Jinyuan Zhang on 2023/2/25.
//

#ifndef LEETCODE_ZJY_PERMUTESOL_H
#define LEETCODE_ZJY_PERMUTESOL_H

#include "vector"
using namespace std;


class permuteSol {
public:
    void backtrace(vector<int>& nums, vector<vector<int>>& res, int first);
    vector<vector<int>> permute(vector<int>& nums);
    void printNums(vector<int> &nums);
    void printRes(vector<vector<int>> &res);
    int pmain();
};


#endif //LEETCODE_ZJY_PERMUTESOL_H
