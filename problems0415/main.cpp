#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string out;
        int carry = 0;
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;

        while (0 <= ptr1 || 0 <= ptr2) {
            if (0 <= ptr1)
                carry += num1[ptr1--] - '0';

            if (0 <= ptr2)
                carry += num2[ptr2--] - '0';

            out.push_back(carry % 10 + '0');
            carry /= 10;
        }

        if (carry)
            out.push_back('1');

        reverse(out.begin(), out.end());

        return out;
    }

    string addStrings36(string num1, string num2) {
        string out;
        int carry = 0;
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;

        while (0 <= ptr1 || 0 <= ptr2) {
            if (0 <= ptr1)
                adder(num1[ptr1--], '0', carry);

            if (0 <= ptr2)
                adder('0', num2[ptr2--], carry);

            out.push_back(index[carry % 36]);
            carry /= 36;
        }

        if (carry)
            out.push_back(index[carry]);

        reverse(out.begin(), out.end());

        return out;
    }

private:
     void adder(char a, char b, int& carry) {
        if (isalpha(a))
            carry += a - 'a' + 10;
        else
            carry += a - '0';

        if (isalpha(b))
            carry += b - 'a' + 10;
        else
            carry += b - '0';
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