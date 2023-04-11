//
// Created by Jinyuan Zhang on 2023/4/9.
//

#include "iostream"

using namespace std;

class LinkListQueue {
    class Node {
    public:
        int data;
        Node* next;
        int priority;

        Node() {
            data = 0;
            next = nullptr;
            priority = -1;
        }

        Node(int x, int p) {
            data = x;
            next = nullptr;
            priority = p;
        }

    };

    class LinkList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkList() {
            head = new Node();
            tail = head;
        }

        ~LinkList() {
            Node *cur = head->next;
            while (cur) {
                delete head;
                head = cur;
                cur = cur->next;
            }
            delete head;
        }

        void addNode(int x, int p) {
            if (empty()) {
                tail->next = new Node(x,p);
                tail = tail->next;
                return;
            }
            Node *cur = head;
            while (p > cur->next->priority) {
                cur = cur->next;
                if (cur->next == nullptr) {
                    break;
                }
            }
            Node *newNode = new Node(x,p);
            if (cur != tail) {
                newNode->next = cur->next;
            } else {
                newNode->next = nullptr;
            }
            cur->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }

        int deleteNode(int index) {
            if (tail == head) {
                cout << "null link list" << endl;
                return -1;
            }
            Node* pre = head;
            for (int i = 0; i < index; ++i) {
                pre = pre->next;
            }
            Node* cur = pre->next;
            int res = cur->data;
            pre->next = cur->next;
            cout << "delete " << res << endl;
            printLinkList();
            delete cur;
            return res;
        }

        bool empty() {
            return head == tail;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail;
        }

        void printLinkList() {
            Node* cur = head->next;
            while (cur != nullptr) {
                cout <<"{" << cur->data <<"," << cur->priority << "}" << "\t";
                cur = cur->next;
            }
            cout << endl;
        }
    };

private:
    LinkList* linkList;
public:
    LinkListQueue() {
        linkList = new LinkList();
    }

    ~LinkListQueue() {
        delete linkList;
    }

    void enQueue(int x,int p) {
        linkList->addNode(x,p);
    }

    int deQueue() {
        if (linkList->empty()) {
            cout << "empty queue" << endl;
            return -1;
        }
        int res = linkList->deleteNode(0);
        return res;
    }

    int front() {
        if (linkList->empty()) {
            cout << "empty queue" << endl;
            return -1;
        }
        return linkList->getHead()->data;
    }

    int back() {
        if (linkList->empty()) {
            cout << "empty queue" << endl;
            return -1;
        }
        return linkList->getTail()->data;
    }

    bool empty() {
        return linkList->empty();
    }

    void printQueue() {
        linkList->printLinkList();
    }
};


int lmain() {
    LinkListQueue linkListQueue;
    linkListQueue.deQueue();
    cout << "front\t" << linkListQueue.front() << endl;
    cout << "back\t" << linkListQueue.back() << endl;
    cout << "empty\t" << linkListQueue.empty() << endl;

    cout << "enQueue" << endl;
    for (int i = 0; i < 10; ++i) {
//        cout << i << endl;
        linkListQueue.enQueue(i,10 - i/2);
//        linkListQueue.printQueue();
    }

    cout << "print queue" << endl;
    linkListQueue.printQueue();

    cout << "pop" << endl;
    cout << linkListQueue.deQueue() << "\t" << linkListQueue.deQueue() << "\t" << linkListQueue.deQueue() << endl;

    cout << "push" << endl;
    for (int i = 0; i < 3; ++i) {
        linkListQueue.enQueue(i,10 - i/2);
    }
    cout << "print queue" << endl;
    linkListQueue.printQueue();
    cout << "end" << endl;
}
