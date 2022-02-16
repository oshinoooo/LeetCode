#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int romanToInt(string str)
    {
        int sum = 0;

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == 'I')
            {
                if (i < str.size() - 1)
                {
                    if (str[i + 1] == 'V')
                    {
                        sum += 4;
                        ++i;
                    }
                    else if (str[i + 1] == 'X')
                    {
                        sum += 9;
                        ++i;
                    }
                    else
                        sum += 1;
                }
                else
                    sum += 1;
            }
            else if (str[i] == 'V')
                sum += 5;
            else if (str[i] == 'X')
            {
                if (i < str.size() - 1)
                {
                    if (str[i + 1] == 'L')
                    {
                        sum += 40;
                        ++i;
                    }
                    else if (str[i + 1] == 'C')
                    {
                        sum += 90;
                        ++i;
                    }
                    else
                        sum += 10;
                }
                else
                    sum += 10;
            }
            else if (str[i] == 'L')
                sum += 50;
            else if (str[i] == 'C')
            {
                if (i < str.size() - 1)
                {
                    if (str[i + 1] == 'D')
                    {
                        sum += 400;
                        ++i;
                    }
                    else if (str[i + 1] == 'M')
                    {
                        sum += 900;
                        ++i;
                    }
                    else
                        sum += 100;
                }
                else
                    sum += 100;
            }
            else if (str[i] == 'D')
                sum += 500;
            else if (str[i] == 'M')
                sum += 1000;
        }
        return sum;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    string in = "MCMXCIV";
    cout << s.romanToInt(in) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
