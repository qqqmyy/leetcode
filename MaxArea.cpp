//
// Created by Jinyuan Zhang on 2023/1/16.
//

#include "MaxArea.h"
#include "iostream"
using namespace std;

int MaxArea::maxArea(vector<int> &height) {
    int n = height.size();
    int i = 0;
    int j = n - 1;
    int max = 0;
    int area = 0;
    int h = 0;
    while (i < j) {
        h = min(height[i],height[j]);
        area = (j-i)*h;
        if (area > max) {
            max = area;
        }
        if (height[i] < height[j]) {
            while (height[i+1] < height[i] && i < j){
                i++;
            }
            i++;
        } else {
            while (height[j-1] < height[j] && i < j) {
                j--;
            }
            j--;
        }
    }
    return max;
}

int MaxArea::maxAreaVio(vector<int> &height) {
    int n = height.size();
    int maxA = 0;
    int area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            area = (j-i)*min(height[i],height[j]);
            if (area > maxA) {
                maxA = area;
            }
        }
    }
    return maxA;
}

int MaxArea::mMain() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
//    for (int i = 0; i < height.size(); ++i) {
//        cout << height[i] << endl;
//    }
    int res = maxArea(height);
    cout<<res<<endl;
}