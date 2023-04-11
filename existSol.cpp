//
// Created by Jinyuan Zhang on 2023/3/3.
//

#include <iostream>
#include "existSol.h"
#include "vector"
#include "string"

using namespace std;

bool existSol::backtrace(vector<vector<char>>& board, vector<vector<bool>>& used, int x, int y, string& word, int k) {
    int m = board.size();
    int n = board[0].size();
    if (board[x][y] != word[k]) {
        return false;
    }
    if (k == word.length() - 1) {
        return true;
    }
    used[x][y] = true;
    int newx;
    int newy;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    bool res = false;
    int len = dir.size();
    for (int i = 0; i < len; i++) {
        newx = x + dir[i][0];
        newy = y + dir[i][1];
        if (newx >= 0 && newx < m && newy >= 0 && newy < n && !used[newx][newy]) {
            res = backtrace(board, used, newx, newy, word, k+1);
            if (res == true) {
                break;
            }
        }
    }
    used[x][y] = false;
    return res;
}

bool existSol::exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();
    bool res = false;
    if (word.length() > m*n) {
        return false;
    }
    vector<vector<bool>> used = vector(m,vector(n,false));
    for (int i = 0;i < m;i++) {
        for (int j  = 0;j < n;j++) {
            res = backtrace(board,used,i,j,word,0);
            if (res == true) {
                return true;
            }
        }
    }
    return res;
}

int existSol::emain() {
    vector<vector<char>> board = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    bool ret = exist(board,"AAAAAAAAAAAAAAB");
    cout << ret << endl;
}