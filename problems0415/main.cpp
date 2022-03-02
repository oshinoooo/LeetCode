#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

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

    string addStrings36(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int carry = 0;
        string out;

        while (0 <= ptr1 || 0 <= ptr2) {
            char tmp;
            if (0 <= ptr1 && 0 <= ptr2)
                tmp = adder(num1[ptr1--], num2[ptr2--], carry);
            else if (0 <= ptr1)
                tmp = adder(num1[ptr1--], '0', carry);
            else
                tmp = adder('0', num2[ptr2--], carry);

            out.push_back(tmp);
        }

        if (carry)
            out.push_back(index[carry]);

        reverse(out.begin(), out.end());

        return out;
    }

private:
     char adder(char a, char b, int& carry) {
        if (isalpha(a))
            carry += a - 'a' + 10;
        else
            carry += a - '0';

        if (isalpha(b))
            carry += b - 'a' + 10;
        else
            carry += b - '0';

        char out = index[carry % 36];

        carry /= 36;

        return out;
    }

private:
    vector<char> index = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b',
                          'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',};
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.addStrings("456", "77") << endl;
    cout << s.addStrings36("az", "az") << endl;
    cout << "---------------------" << endl;
    return 0;
}
