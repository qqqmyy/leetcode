//
// Created by Jinyuan Zhang on 2023/1/14.
//

#include <vector>
#include "Median.h"
#include "iostream"
using namespace std;
int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
//    cout << "get " << k <<"th element"<<endl;
    int index1 = 0;
    int index2 = 0;
    int m = nums1.size();
    int n = nums2.size();
    int newIndex1 = index1;
    int newIndex2 = index2;
    int count = 0;
    while (true) {
//        cout << "index1: " << index1 << "\tindex2: " << index2 << "\tk: " << k << endl;
        if (index1 == m) {
//            cout<<"return nums2[index2 + k - 1]: " << nums2[index2 + k - 1] << endl;
            return nums2[index2 + k - 1];
        }
        if (index2 == n) {
//            cout<<"return nums1[index1 + k - 1]: " << nums1[index1 + k - 1] << endl;
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
//            cout<<"return min(nums1[index1],nums2[index2]): " << min(nums1[index1],nums2[index2]) << endl;
            return min(nums1[index1],nums2[index2]);
        }
        if (nums1[index1 + k/2 - 1] > nums2[index2 + k/2 - 1]) {
            newIndex2 = min(index2 + k/2, n);
//            cout << "new index 2: " << newIndex2 << endl;
            k = k - (newIndex2 - index2);
            index2 = newIndex2;
        } else {
            newIndex1 = min(index1 + k/2, m);
//            cout << "new index 1: " << newIndex1 << endl;
            k = k - (newIndex1 - index1);
            index1 = newIndex1;
        }
//        cout << "end: index1: " << index1 << "\tindex2: " << index2 << "\tk: " << k << endl;
    }
    return 0;
}

double Median::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    int length = m + n;
    cout << "length: " << length << endl;
    if (length % 2 == 1) {
        return getKthElement(nums1,nums2,length/2 + 1);
    } else {
        double res = ((double)(getKthElement(nums1,nums2,length/2) + (double)getKthElement(nums1,nums2,length/2 + 1))/2);
        return res;
    }
}

int Median::MedianMain() {
    std::vector<int> nums1 ={1};
    vector<int> nums2 = {2,3,4,5,6};
    cout << findMedianSortedArrays(nums1,nums2) << endl;
//    cout << nums1.size() <<endl;
}