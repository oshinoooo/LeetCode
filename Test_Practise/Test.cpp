//
// Created by LYL on 2022/2/2.
//

#include <iostream>
#include "Test.h"

using namespace std;

Test::Test() : number(0) {
    cout << "Test()" << endl;
}

Test::Test(const Test& t) {
    this->number = t.number;
    cout << "Test(const Test& t)" << endl;
}

Test::~Test() {
    cout << "~Test()" << endl;
}
