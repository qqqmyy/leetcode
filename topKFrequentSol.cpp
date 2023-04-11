//
// Created by Jinyuan Zhang on 2023/3/4.
//

#include <iostream>
#include <unordered_map>
#include "topKFrequentSol.h"
using namespace std;

bool cmp (pair<int,int>&x, pair<int,int>&y) {
    return x.second > y.second;
}

vector<int> topKFrequentSol::topKFrequent(vector<int> &nums, int k) {
    int n =  nums.size();
    vector<int> res;
    unordered_map<int,int> frequent;
    cout << "topK" << endl;
    for (int i = 0; i < n;i++) {
        frequent[nums[i]]++;
    }
    vector<pair<int,int>> fre;
    for (auto& it:frequent) {
        fre.emplace_back(it);
    }
    sort(fre.begin(),fre.end(),cmp);
    int count = 0;
    for (auto& it:fre) {
        res.emplace_back(it.first);
        count++;
        if(count >= k) {
            break;
        }
    }
    return res;
}

int topKFrequentSol::tmain() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = topKFrequent(nums,k);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t" << endl;
    }
}