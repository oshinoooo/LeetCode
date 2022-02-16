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
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;

        pair<int, int> lengths = findLengths(num);
        if (lengths.first == 0 && lengths.second == 0)
            return false;

        string num1 = num.substr(0, lengths.first);
        string num2 = num.substr(lengths.first, lengths.second);
        if (num1[0] == '0' && 1 < num1.size() || num2[0] == '0' && 1 < num2.size())
            return false;

        string expect = num.substr(0, lengths.first + lengths.second);

        while (expect.size() < num.size()) {
            string next = myAdd(num1, num2);
            if (next[0] == '0' && 1 < next.size())
                return false;
            expect += next;
            num1 = num2;
            num2 = next;
        }

        return expect.substr(0, num.size()) == num;
    }

private:
    pair<int, int> findLengths(string& num) {
        for (int i = 1; i <= num.size() - 2; ++i) {
            string num1 = num.substr(0, i);
            for (int j = 1; j <= num.size() - i - 1; ++j) {
                string num2 = num.substr(i, j);
                string sum = myAdd(num1, num2);
                int length = min(num.size() - i - j, sum.size());
                if (sum.substr(0, length) == num.substr(i + j, length)) {
                    return {i, j};
                }
            }
            if (num[0] == '0')
                return {0, 0};
        }
        return {0, 0};
    }

    string myAdd(string& a, string& b) {
        string out;
        int ptr1 = a.size() - 1;
        int ptr2 = b.size() - 1;
        int carry = 0;
        while (0 <= ptr1 || 0 <= ptr2) {
            if (0 <= ptr1 && 0 <= ptr2)
                carry += a[ptr1--] - '0' + b[ptr2--] - '0';
            else if (0 <= ptr1)
                carry += a[ptr1--] - '0';
            else
                carry += b[ptr2--] - '0';
            out.push_back(carry % 10 + '0');
            carry /= 10;
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
    cout << s.isAdditiveNumber("198019823962") << endl;
    cout << "---------------------" << endl;
    return 0;
}
