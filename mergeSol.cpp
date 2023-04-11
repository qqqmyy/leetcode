//
// Created by Jinyuan Zhang on 2023/2/28.
//

#include "mergeSol.h"
#include "vector"
#include "iostream"
using namespace std;

bool mergeSol::greaterSort(vector<int> &x, vector<int> &y) {
    if (x[0] >= y[0]) {
        return true;
    }
    return false;
}

vector<vector<int>> mergeSol::merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    int n = intervals.size();
    std::sort(intervals.begin(),intervals.end(),greaterSort);
    for(int i = 0; i < n; i++) {
        cout << intervals[i][0] << ", " << intervals[i][1] << endl;
    }
}

int mergeSol::mMain() {
    vector<vector<int>> intervals;
    vector<int> temp = {8,10};
    intervals.push_back(temp);
    temp = {15,18};
    intervals.push_back(temp);
    temp = {2,6};
    intervals.push_back(temp);
    temp = {1,3};
    intervals.push_back(temp);
    int n = intervals.size();
    for(int i = 0; i < n; i++) {
        cout << intervals[i][0] << ", " << intervals[i][1] << endl;
    }
    merge(intervals);
}