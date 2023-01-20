//
// Created by Jinyuan Zhang on 2023/1/19.
//

#ifndef LEETCODE_ZJY_REMOVENTHFROMENDSOL_H
#define LEETCODE_ZJY_REMOVENTHFROMENDSOL_H

using namespace std;

//Definition for singly-linked list.

class removeNthFromEndSol {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    int rMain();
};


#endif //LEETCODE_ZJY_REMOVENTHFROMENDSOL_H
