//
// Created by Jinyuan Zhang on 2023/1/20.
//

#include "mergeTwoListsSol.h"
#include "iostream"

void printList(ListNode *head) {
//    cout << "start print" << endl;
    if (head == nullptr) {
        cout << "[]" << endl;
        return;
    }
    ListNode *cur = head;
    while (cur != nullptr) {
        cout << cur->val << "\t";
        cur = cur->next;
    }
    cout << "" << endl;
//    cout << "\t print end" << endl;
}

void insertNode(ListNode* prev, ListNode* node) {
    ListNode* next = prev->next;
    prev->next = node;
    node->next = next;
}

ListNode* mergeTwoListsSol::mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    ListNode* res;
    ListNode* toAdd;
    ListNode* resCur;
    ListNode* resNext;
    ListNode* toAddNext;
    if (list1->val <= list2->val) {
        res = list1;
        toAdd = list2;
    } else {
        res = list2;
        toAdd = list1;
    }
    resCur = res;
    while (resCur != nullptr || toAdd != nullptr) {
        if (toAdd == nullptr) {
            return res;
        }
        resNext = resCur->next;
        if (resNext == nullptr) {
            if (toAdd != nullptr) {
                resCur->next = toAdd;
            }
            return res;
        }
        if (resNext->val <= toAdd->val) {
            resCur = resNext;
        } else {
            toAddNext = toAdd->next;
            insertNode(resCur,toAdd);
            toAdd = toAddNext;
        }
    }
    return res;
}

//ListNode* mergeTwoListsSol::mergeTwoLists(ListNode *list1, ListNode *list2) {
//    ListNode* cur1 = list1;
//    ListNode* cur2 = list2;
//    ListNode* res;
//    if (cur1->val <= cur2->val) {
//        res = cur1;
//        cur1 = cur1->next;
//    } else {
//        res = cur2;
//        cur2 = cur2->next;
//    }
//    ListNode* resCur = res;
//    cout << "res: " << res->val << endl;
//    cout << "resCur: " << resCur->val << endl;
//    while (cur1 != nullptr || cur2 != nullptr) {
//        cout << "while begin" << endl;
//        if (cur1 == nullptr) {
//            resCur->next = cur2;
//            if (cur2->next != nullptr) {
//                cur2 = cur2->next;
//            } else {
//                cur2 = nullptr;
//            }
//        }
//        if (cur2 == nullptr) {
//            resCur->next = cur1;
//            if (cur1->next != nullptr) {
//                cur1 = cur1->next;
//            } else {
//                cur1 = nullptr;
//            }
//        }
//        if (cur1->val <= cur2->val) {
//            resCur->next = cur1;
//            cur1 = cur1->next;
//        } else {
//            resCur->next = cur2;
//            cur2 = cur2->next;
//        }
//        resCur = resCur->next;
//        cout << "cur1: " << cur1->val << endl;
//        cout << "cur2: " << cur2->val << endl;
//        printList(res);
//    }
//    return res;
//}


int mergeTwoListsSol::mMain() {
    int a1[] = {1,2,3};
    int a2[] = {1};
    int len1 = end(a1) - begin(a1);
    int len2 = end(a2) - begin(a2);
    ListNode *h1;
    ListNode *h2;
    if (len1 > 0) {
        h1 = new ListNode(a1[0]);
        ListNode *c1 = h1;
        for (int i = 1; i < len1; ++i) {
            c1->next = new ListNode(a1[i]);
            c1 = c1->next;
        }
    }
    if (len2 > 0) {
        h2 = new ListNode(a2[0]);
        ListNode *c2 = h2;
        for (int i = 1; i < len2; ++i) {
            c2->next = new ListNode(a2[i]);
            c2 = c2->next;
        }
    }
    printList(h1);
    printList(h2);
//    cout << "here" << endl;
    ListNode* res = mergeTwoLists(h1,h2);
//    cout << "res" << endl;
    printList(res);
}