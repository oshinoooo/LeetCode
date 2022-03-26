#include <iostream>

using namespace std;

class Solution {
public:
    static void getNumber1() {}
    static void getNumber2() {}
    static void getNumber3() {}
};

int main() {
    cout << "--------------------" << endl;

    Solution s1;
    Solution s2;

    cout << s1.getNumber1 << endl;
    cout << s1.getNumber2 << endl;
    cout << s1.getNumber3 << endl;

    cout << s2.getNumber1 << endl;
    cout << s2.getNumber2 << endl;
    cout << s2.getNumber3 << endl;

    cout << "--------------------" << endl;
    return 0;
}