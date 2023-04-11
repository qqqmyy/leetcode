//
// Created by Jinyuan Zhang on 2023/4/8.
//

#include "iostream"
using namespace std;

#define CAPACITY 100

class ArrayQueue {
private:
    int size;
    int* queue;

public:
    ArrayQueue() {
        size = 0;
        queue = new int[CAPACITY];
//        int queue[CAPACITY];
//        queue = nullptr;
//        queue = new int();
    }

    ~ArrayQueue() {
        delete queue;
        queue = nullptr;
    }

    void push(int x) {
        queue[size++] = x;
        return;
    }

    int pop() {
        if (size == 0) {
//            assert(("empty queue", size));
            cout << "warning: empty queue" << endl;
            return -1;
        }
        int res;
        res = queue[0];
        for (int i = 0; i < size - 1; ++i) {
            queue[i] = queue[i+1];
        }
        size--;
        return res;
    }

    bool empty() {
        return !size;
    }

    int front() {
        if (size == 0) {
            cout << "warning: empty queue" << endl;
        }
        return queue[0];
    }

    int back() {
        if (size == 0) {
            cout << "warning: empty queue" << endl;
        }
        return queue[size - 1];
    }

    void printQueue() {
        for (int i = 0; i < size; ++i) {
            cout << queue[i] << "\t" << endl;
        }
    }

};

int Amain() {
    ArrayQueue arrayQueue;
    arrayQueue.pop();
    cout << "front\t" << arrayQueue.front() << endl;
    cout << "back\t" << arrayQueue.back() << endl;
    cout << "empty\t" << arrayQueue.empty() << endl;

    for (int i = 0; i < 10; ++i) {
        arrayQueue.push(i);
    }

    cout << "print queue" << endl;
    arrayQueue.printQueue();

    cout << "pop" << endl;
    cout << arrayQueue.pop() << "\t" << arrayQueue.pop() << "\t" << arrayQueue.pop() << endl;

    cout << "push" << endl;
    for (int i = 0; i < 3; ++i) {
        arrayQueue.push(i);
    }
    cout << "print queue" << endl;
    arrayQueue.printQueue();
}
