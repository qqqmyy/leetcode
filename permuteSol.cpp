//
// Created by Jinyuan Zhang on 2023/2/25.
//

#include <iostream>
#include "permuteSol.h"
#include "vector"
using namespace std;

void permuteSol::backtrace(vector<int> &nums, vector<vector<int>> &res, int first) {
    int n = nums.size();
    if (first == n) {
        cout<<"reach n" << endl;
        res.emplace_back(nums);
    }
    for (int i = first; i < n; i++) {
        swap(nums[first],nums[i]);
        cout << "swap nums" << endl;
        printNums(nums);
        backtrace(nums,res,first+1);
        swap(nums[first],nums[i]);
    }
}

using namespace std;

vector<vector<int>> permuteSol::permute(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    backtrace(nums,res,0);
    return res;
}

void permuteSol::printNums(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cout << endl;
}

void permuteSol::printRes(vector<vector<int>> &res) {
    for (int i = 0; i < res.size(); ++i) {
        printNums(res[i]);
    }
}

int permuteSol::pmain() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    printRes(res);
    return 0;
}
