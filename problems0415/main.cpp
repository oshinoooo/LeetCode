#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int carry = 0;
        string out;

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
    cout << s.addStrings("456", "77") << endl;
    cout << "---------------------" << endl;
    return 0;
}
