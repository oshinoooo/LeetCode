#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string solve(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();

        if (s_size != t_size)
        {
            string tmp;
            for (int i = 0; i < abs(s_size - t_size); ++i)
                tmp.push_back('0');

            if (s_size < t_size)
                s.insert(s.begin(), tmp.begin(), tmp.end());
            else
                t.insert(t.begin(), tmp.begin(), tmp.end());
        }

        int carry = 0;
        for (int i = max(s_size, t_size) - 1; i >= 0; --i)
        {
            int sum = s[i] - '0' + t[i] - '0' + carry;
            if (sum > 9)
            {
                carry = 1;
                sum %= 10;
            }
            else
                carry = 0;

            s[i] = sum + '0';
        }

        if (carry)
            s.insert(s.begin(), '1');

        return s;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.solve("9", "123") << endl;
    cout << "-------------------------" << endl;
    return 0;
}
