//
// Created by Jinyuan Zhang on 2023/4/9.
//


#include "iostream"
using namespace std;

class CallStackOverFlow {
private:
    int count = 0;
public:
        int foo() {
//            cout << count++ << "\t";
            foo();
        };
};


int Cmain() {
//    CallStackOverFlow callStackOverFlow;
//    callStackOverFlow.foo();
    cout << "start" << endl;
    double x[1048576];
}