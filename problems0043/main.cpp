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

using namespace std;

class Solution {
public:
    string multiply1(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        vector<string> tmp;
        int count = 0;
        for (int i = num2.size() - 1; 0 <= i; --i)
            tmp.push_back(mul(num1, num2[i], count++));

        string out = "0";
        for (int i = 0; i < tmp.size(); ++i)
            out = add(out, tmp[i]);

        return out;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> tmp = vector<int>(m + n, 0);
        for (int i = m - 1; 0 <= i; --i) {
            for (int j = n - 1; 0 <= j; --j) {
                tmp[i + 1 + j + 1 - 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = tmp.size() - 1; 0 < i; --i) {
            tmp[i - 1] += tmp[i] / 10;
            tmp[i] %= 10;
        }

        string out;
        for (int i = 0; i < tmp.size(); ++i) {
            if (i == 0 && tmp[0] == 0)
                continue;
            out.push_back(tmp[i] + '0');
        }

        return out;
    }

private:
    string add(const string& num1, const string& num2) {
        string out(max(num2.size(), num1.size()) + 1, '0');

        int carry = 0;
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        int curr = out.size() - 1;

        while (0 <= ptr1 || 0 <= ptr2) {
            int tmp;
            if (0 <= ptr1 && 0 <= ptr2)
                tmp = num1[ptr1--] - '0' + num2[ptr2--] - '0' + carry;
            else if (0 <= ptr1)
                tmp = num1[ptr1--] - '0' + carry;
            else
                tmp = num2[ptr2--] - '0' + carry;

            out[curr--] = tmp % 10 + '0';
            carry = tmp / 10;
        }

        if (carry)
            out[curr--] = '1';

        if (*out.begin() == '0')
            return out.substr(1);

        return out;
    }

    string mul(const string& num1, const char& c, const int& zeros) {
        string out(num1.size() + 1, '0');
        int carry = 0;
        int curr = out.size() - 1;

        for (int i = num1.size() - 1; 0 <= i; --i) {
            int tmp = (num1[i] - '0') * (c - '0') + carry;
            out[curr--] = tmp % 10 + '0';
            carry = tmp / 10;
        }

        if (carry)
            out[curr--] = carry + '0';

        if (*out.begin() == '0')
            out = out.substr(1);

        for (int i = 0; i < zeros; ++i)
            out.push_back('0');

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.multiply("2", "3") << endl;
    cout << "---------------------" << endl;
    return 0;
}
