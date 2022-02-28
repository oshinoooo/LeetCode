//
// Created by LYL on 2022/2/27.
//

#ifndef TEST_SMARTPTR_B_H
#define TEST_SMARTPTR_B_H

#include <iostream>
#include <memory>
#include "A.h"

using namespace std;

class B {
public:
    B() {
        cout << "B()" << endl;
    }

    ~B() {
        cout << "~B()" << endl;
    }

    shared_ptr<A> ptr;
};

#endif //TEST_SMARTPTR_B_H
