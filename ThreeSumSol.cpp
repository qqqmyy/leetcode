//
// Created by Jinyuan Zhang on 2023/1/16.
//

#include "ThreeSumSol.h"
#include "iostream"
#include "set"


vector<vector<int>> ThreeSumSol::threeSum(vector<int> &nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ress;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int k = n - 1;
        int t = -nums[i];
        for (int j = i+1; j < n; ++j) {
            if (j > i+1  && nums[j] == nums[j-1]) {
                continue;
            }
//            int k = n-1;
//            int target = 0 - (nums[i] + nums[j]);
//            while (nums[k] > target && k > j) {
//                k--;
//            }
            while (nums[j] + nums[k] > t && k > j) {
                k--;
            }
            if (k == j) {
                break;
            }
//            if (nums[k] == target) {
            if (nums[j] + nums[k] == t) {
                res = {nums[i],nums[j],nums[k]};
                ress.push_back(res);
            }
        }
    }
    return ress;
}

//
//vector<vector<int>> ThreeSumSol::threeSum(vector<int> &nums) {
//    sort(nums.begin(),nums.end());
////    for (int i = 0; i < nums.size(); ++i) {
////        cout << nums[i] << " ";
////    }
////    cout << "" << endl;
//    int n = nums.size();
//    vector<vector<int>> ress;
//    vector<int> res;
//    for (int i = 0; i < n; ++i) {
////        cout << "i = " << i << endl;
//        for (int j = i+1; j < n; ++j) {
////            cout << "j = " << j << endl;
////            for (int k = j+1; k < n; ++k) {
//////                cout << "i = " << i << " j = " << j << " k = " << k << endl;
//////                cout << "nums:" << nums[i] << " " << nums[j] << " " << nums[k] << " "<< endl;
////                if (nums[i] + nums[j] + nums[k] == 0) {
////                    res = {nums[i],nums[j],nums[k]};
////                    ress.push_back(res);
////                }
////                if (k < n-1){
////                    if (nums[k+1] == nums[k]) {
////                        k++;
////                    }
////                }
////            }
//            int k = n-1;
//            int target = 0 - (nums[i] + nums[j]);
//            while (nums[k] > target && k > j) {
//                k--;
//            }
//            if (k == j) {
//                break;
//            }
//            if (nums[k] == target) {
//                res = {nums[i],nums[j],nums[k]};
//                ress.push_back(res);
//            }
//            if (j < n-1) {
//                if (nums[j+1] == nums[j]) {
//                    j++;
//                }
//            }
//        }
//        if (i < n-1) {
//            if (nums[i+1] == nums[i]) {
//                i++;
//            }
//        }
//    }
//    set<vector<int>> s(ress.begin(),ress.end());
//    ress.assign(s.begin(),s.end());
//    return ress;
//}

int ThreeSumSol::tMain() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << "" << endl;
    }
    return 0;
}