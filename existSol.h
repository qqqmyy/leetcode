//
// Created by Jinyuan Zhang on 2023/3/3.
//

#ifndef LEETCODE_ZJY_EXISTSOL_H
#define LEETCODE_ZJY_EXISTSOL_H

#include "vector"
#include "string"

using namespace std;


class existSol {

public:
    bool exist(vector<vector<char>>& board, string word);
    int emain();
    bool backtrace(vector<vector<char>> &board, vector<vector<bool>> &used, int x, int y, string &word, int k);
};


#endif //LEETCODE_ZJY_EXISTSOL_H
