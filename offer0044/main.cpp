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
    int findNthDigit1(int n)
    {
        int cur = 1;
        vector<int> sequence = {0};
        while (sequence.size() < n + 1)
        {
            int tmp = cur;
            vector<int> tmp_seq;
            while (0 < tmp)
            {
                tmp_seq.push_back(tmp % 10);
                tmp /= 10;
            }
            reverse(tmp_seq.begin(), tmp_seq.end());
            sequence.insert(sequence.end(), tmp_seq.begin(), tmp_seq.end());
            ++cur;
        }
        return sequence[n];
    }

    int findNthDigit(int n)
    {
        double start = 0.1;
        int digit = 0;
        long long count = 0;

        while (count < n)
        {
            start *= 10;
            count += 9 * start * ++digit;
        }

        count -= 9 * start * digit;
        n -= count;
        if (n == 0)
            return 9;

        int number = (n - 1) / digit + 1 + start - 1;

        int out;
        int position = n % digit;
        if (position == 0)
            out = number % 10;
        else
        {
            vector<int> num;
            while (0 < number)
            {
                num.push_back(number % 10);
                number /= 10;
            }
            out = num[num.size() - position];
        }
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.findNthDigit(10000) << endl;
    cout << "---------------------" << endl;
    return 0;
}

// 10 11 12 13 14 15
//  1  0  1  1  1  2