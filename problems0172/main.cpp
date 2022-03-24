#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n) {
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.trailingZeroes(5) << endl;
    cout << "--------------------" << endl;
    return 0;
}