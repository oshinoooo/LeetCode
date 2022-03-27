#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n & 0b11;

        while (n) {
            if (flag == 0b01) {
                if ((n & 0b11) == 0b01)
                    n >>= 2;
                else
                    return false;
            }
            else if (flag == 0b10) {
                if ((n & 0b11) == 0b10)
                    n >>= 2;
                else
                    return false;
            }
            else
                return false;
        }

        return true;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.hasAlternatingBits(0b10101010) << endl;
    cout << "--------------------" << endl;
    return 0;
}