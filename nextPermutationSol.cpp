//
// Created by Jinyuan Zhang on 2023/1/20.
//

#include "nextPermutationSol.h"
#include "iostream"

void printNums(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cout << endl;
}

void swap(int i, int j, vector<int>& nums) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void nextPermutationSol::nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if (n == 1 || n == 0) {
        return;
    }
    if (nums[n-1] > nums[n-2]) {
        swap(n-1,n-2,nums);
        return;
    }
    int i;
    int min = 1000;
    int minIndex = -1;
    for (i = n-2; i >= 1; --i) {
        if (nums[i-1] < nums[i]) {
            break;
        }
    }
    cout << "i = " << i << endl;
    if (i == 0) {
        sort(nums.begin(),nums.end());
        return;
    }
    for (int j = i; j < n; ++j) {
        if (nums[j] < min && nums[j] > nums[i-1]) {
            min = nums[j];
            minIndex = j;
        }
    }
    swap(minIndex,i-1,nums);
//    cout << "temp res: ";
//    printNums(nums);
    sort(nums.begin() + i, nums.end());
}

int nextPermutationSol::nMain() {
    vector<int> nums = {3,2,1};
    printNums(nums);
    nextPermutation(nums);
    printNums(nums);
}