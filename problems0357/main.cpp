#include <iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;

        if (n == 1)
            return 10;

        int out = 10;
        int cur = 9;

        for (int i = 0; i < n - 1; ++i) {
            cur *= 9 - i;
            out += cur;
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) << endl;
    cout << "--------------------" << endl;
    return 0;
}