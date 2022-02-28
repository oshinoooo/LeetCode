//
// Created by LYL on 2022/2/27.
//

#ifndef TEST_SMARTPTR_A_H
#define TEST_SMARTPTR_A_H

#include <iostream>
#include <memory>
#include "B.h"

using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

    shared_ptr<B> ptr;
};

#endif //TEST_SMARTPTR_A_H
