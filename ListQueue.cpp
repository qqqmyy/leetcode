//
// Created by Jinyuan Zhang on 2023/4/9.
//

#include "iostream"
#include "list"

using namespace std;
template <typename T>
class Element {
private:
    T data;
    int priority;
public:
    Element() {
        data = -1;
        priority = -1;
    }

    Element(T d, int p) {
        data = d;
        priority = p;
    }

    bool larger(Element element) {
        return priority > element.priority;
    }

    void print() {
        cout <<"{" << data <<"," << priority << "}" << "\t";
    }
};

//template <typename T>
class ListQueue {
private:
//    list<int> l;
    list<Element<int>> l;

public:
    void enQueue(Element<int> x) {
//        l.push_back(x);
//        list<Element<int>>::iterator it = l.begin();
//        l.insert(it,x);
        for (auto it = l.begin(); it != l.end() ; it++) {
            Element<int> e = *it;
            if (e.larger(x)) {
                l.insert(it,x);
                return;
            }
        }
        l.push_back(x);
        return;
    }

    Element<int> deQueue() {
        assert(!empty());
        Element<int> res = l.front();
        l.pop_front();
        return res;
    }

    bool empty() {
        return l.empty();
    }

    Element<int> front() {
        return l.front();
    }

    Element<int> back() {
        return l.back();
    }

    void printQueue() {
        typename list<Element<int>>::iterator it;
        for (it = l.begin(); it != l.end();it++) {
            Element<int> e = *it;
            e.print();
        }
//        for (auto it = l.begin();it != l.end();it++) {
//            cout << *it << "\t";
//        }
        cout << endl;
    }

};


int main() {
    ListQueue linkListQueue;
    cout << "front\t";
    linkListQueue.front().print();
    cout << "back\t";
    linkListQueue.back().print();
    cout << "empty\t" << linkListQueue.empty() << endl;

    cout << "enQueue" << endl;
    for (int i = 0; i < 10; ++i) {
//        cout << i << endl;
        Element<int> e = *new Element<int>(i, 10 - i/2);
        linkListQueue.enQueue(e);
//        linkListQueue.printQueue();
    }

    cout << "print queue" << endl;
    linkListQueue.printQueue();

    cout << "pop" << endl;
    for (int i = 0; i < 3; ++i) {
        linkListQueue.deQueue();
    }

    cout << "push" << endl;
    for (int i = 0; i < 3; ++i) {
        Element<int> e = *new Element<int>(i, 10 - i/2);
        linkListQueue.enQueue(e);
    }
    cout << "print queue" << endl;
    linkListQueue.printQueue();
    cout << "end" << endl;
}
