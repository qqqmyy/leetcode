//
// Created by Jinyuan Zhang on 2023/1/20.
//

#ifndef LEETCODE_ZJY_MERGETWOLISTSSOL_H
#define LEETCODE_ZJY_MERGETWOLISTSSOL_H

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class mergeTwoListsSol {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    int mMain();
};


#endif //LEETCODE_ZJY_MERGETWOLISTSSOL_H
