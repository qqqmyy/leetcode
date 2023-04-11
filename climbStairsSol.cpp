//
// Created by Jinyuan Zhang on 2023/2/25.
//

#include "climbStairsSol.h"
#include "iostream"
using namespace std;

int climbStairsSol::climbStairs(int n) {
    cout<<n<<endl;
    if (n == 0 || n == 1) {
        return n;
    }
    if (n == 2) {
        return 2;
    }
    int res = climbStairs(n-1) + climbStairs(n-2);
    return res;
}