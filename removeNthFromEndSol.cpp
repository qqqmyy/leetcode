//
// Created by Jinyuan Zhang on 2023/1/19.
//

#include "removeNthFromEndSol.h"
#include "iostream"
#include "stack"
#include "mergeTwoListsSol.h"

using namespace std;

removeNthFromEndSol::ListNode * removeNthFromEndSol::removeNthFromEnd(ListNode *head, int n) {
    if (head->next == nullptr) {
        return nullptr;
    }
    stack<ListNode*> nodeStack;
    ListNode *cur = head;
    while (cur != nullptr) {
        nodeStack.push(cur);
        cur = cur->next;
    }
//    cout << "stack length: " << nodeStack.size() << endl;
    if (n > nodeStack.size()) {
        return head;
    }
    if (n == 1) {
        nodeStack.pop();
        cur = nodeStack.top();
        cur->next = nullptr;
        return head;
    }
    if (n == nodeStack.size()) {
        head = head->next;
        return head;
    }
    for (int i = 0; i < n-2; ++i) {
        nodeStack.pop();
    }
    ListNode *next = nodeStack.top();
//    cout << "next.val = " << next->val << endl;
    nodeStack.pop();
    nodeStack.pop();
    ListNode * pre = nodeStack.top();
    pre->next = next;
    return head;
}

int removeNthFromEndSol::rMain() {
    ListNode *head = new ListNode;
    head->val = 1;
    head->next = nullptr;
    ListNode *pre = head;
    for (int i = 2; i < 3; ++i) {
        ListNode *temp = new ListNode;
        temp->val = i;
        temp->next = nullptr;
        pre->next = temp;
        pre = temp;
    }
    ListNode *cur = head;
    while (cur != nullptr) {
        cout << cur->val << "\t";
        cur = cur->next;
    }
    cout << " " << endl;
    ListNode * res = removeNthFromEnd(head,2);
    cur = res;
    while (cur != nullptr) {
        cout << cur->val << "\t";
        cur = cur->next;
    }
}