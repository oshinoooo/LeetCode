#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>
#include <ctime>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string out;

        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        int carry = 0;

        while (0 <= ptr1 || 0 <= ptr2) {
            int tmp;
            if (0 <= ptr1 && 0 <= ptr2)
                tmp = carry + num1[ptr1--] - '0' + num2[ptr2--] - '0';
            else if (0 <= ptr1)
                tmp = carry + num1[ptr1--] - '0';
            else
                tmp = carry + num2[ptr2--] - '0';

            out.push_back(tmp % 10 + '0');
            carry = tmp / 10;
        }

        if (carry)
            out.push_back('1');

        reverse(out.begin(), out.end());
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.addStrings("1", "9") << endl;
    cout << "---------------------" << endl;
    return 0;
}
