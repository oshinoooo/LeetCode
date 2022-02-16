#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int num = 0;
        int sign = 1;
        bool started = false;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                started = true;

                if (num > 214748364)
                    return sign == 1 ? 2147483647 : -2147483648;
                else if (num == 214748364)
                {
                    if (sign == 1 && s[i] >= '7')
                        return 2147483647;
                    else if (sign == -1 && s[i] >= '8')
                        return -2147483648;
                    else
                        num = num * 10 + (s[i] - '0');
                }
                else
                    num = num * 10 + (s[i] - '0');
            }
            else
            {
                if (started)
                    break;
                else if (s[i] == ' ')
                    continue;
                else if (s[i] == '+')
                {
                    started = true;
                    sign = 1;
                }
                else if (s[i] == '-')
                {
                    started = true;
                    sign = -1;
                }
                else
                    break;
            }
        }

        return num * sign;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    string in = "-2147483647";
    cout << s.myAtoi(in) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
