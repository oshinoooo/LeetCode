#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> plusOne1(vector<int>& digits)
    {
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] == 9)
                continue;

            for (int j = digits.size() - 1; j >= i; --j)
            {
                digits[j] += 1;
                if (digits[j] > 9)
                    digits[j] = 0;
                else
                    return digits;
            }
        }

        for (auto& digit : digits) digit = 0;
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }

    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (i == digits.size() - 1)
                ++digits[i];
            else
                digits[i] += carry;

            if (digits[i] > 9)
            {
                digits[i] -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
                break;
            }
        }

        if (carry == 1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    vector<int> in = {9,8,9,9};
    vector<int> out = s.plusOne(in);
    for (auto ou : out)
        cout << ou;
    cout << endl;
    cout << "------------------" << endl;
    return 0;
}