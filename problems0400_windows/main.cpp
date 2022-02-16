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

class Solution
{
public:
    int findNthDigit(int n)
    {
        long long digit = 1;
        long long num = 9;
        long long tmp = 9;

        while (tmp < n)
        {
            num *= 10;
            ++digit;
            tmp += digit * num;
        }

        int bias = n - (tmp - digit * num);

        int start = pow(10, digit - 1) - 1;
        int number = (bias - 1) / digit + 1 + start;

        int position = bias % digit;
        int out;
        if (position == 0)
            out = number % 10;
        else
        {
            for (int i = 0; i < digit - position + 1; ++i)
            {
                out = number % 10;
                number /= 10;
            }
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    int tmp;
    while (cin >> tmp)
        cout << s.findNthDigit(tmp) << endl;
    cout << "---------------------" << endl;
    return 0;
}
