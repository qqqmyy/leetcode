//
// Created by Jinyuan Zhang on 2023/4/9.
//
#include <iostream>
template<class param_t>
class Foo
{
    typedef typename param_t::baz sub_t;
};


//class Apple {
//
//public:
//    int age;
//    int size;
//    int price;
//
//    typedef int AppleInt;
//
//    // returns 0 if other == this; 1 if other < this, -1 if other > this
////    int compare(Apple other) {
////        if (size == other.size) return 0;
////
////        if (size > other.size) return 1;
////        else return -1;
////    }
//};
//
//class t {
//public:
//    T data;
//    int priority;
//
//    int compare() {
//
//    }
//};
//
//template <class T>
//class ZJY {
//    typedef int myZJYInt;
//public:
//    typedef class T::AppleInt                  sub;
//
//    void test() {
//        myZJYInt x = 10;
//        ZJY::myZJYInt xx = 1;
//        sub a;
//    }
//};


template <typename V> V myMin(V x, V y){
    if (x < y) {
        return x;
    }
    return y;
}

template <typename T, typename K>
class Adder {
public:
    T add(T x, T y) {
        std::cout <<"add1" << std::endl;
        return x + y;
    }

    T add(T x, K y) {
        std::cout <<"add2" << std::endl;
        return x + y;
    }
//    double add(double x, double y) {
//        return x + y;
//    }
//
//    double add(int x, double y) {
//        return x + y;
//    }
};

int lmain2() {
    std::cout << myMin(3.33,4.88) << std::endl;
//    Adder<int, double> adder;
//    std::cout << adder.add(1, 2) << std::endl;
//
//    std::cout << adder.add(1.0, 2.0) << std::endl;
    return 0;
}