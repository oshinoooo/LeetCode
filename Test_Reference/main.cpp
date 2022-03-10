#include <iostream>

using namespace std;

int main() {
    cout << "--------------------" << endl;

    int a = 2;
    cout << a << endl;
    cout << &a << endl;

    int&& b = move(a);
    cout << a << endl;
//    cout << &b << endl;

    cout << "--------------------" << endl;
    return 0;
}
