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
    string convertToBase7(int num) {
        if (num == 0)
            return "0";

        string out;

        bool negative = false;
        if (num < 0) {
            negative = true;
            num = abs(num);
        }

        while (num) {
            out.push_back(num % 7 + '0');
            num /= 7;
        }

        if (negative)
            out.push_back('-');

        reverse(out.begin(), out.end());

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.convertToBase7(-7) << endl;
    cout << "--------------------" << endl;
    return 0;
}
