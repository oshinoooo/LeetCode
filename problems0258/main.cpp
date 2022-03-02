#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num / 10) {
            int tmp = 0;

            while (num) {
                tmp += num % 10;
                num /= 10;
            }

            num = tmp;
        }

        return num;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.addDigits(38) << endl;
    cout << "--------------------" << endl;
    return 0;
}
