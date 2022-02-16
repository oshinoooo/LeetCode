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
    int hammingDistance(int x, int y)
    {
        int count = 0;
        while (0 < x || 0 < y)
        {
            if ((x & 1) ^ (y & 1))
                ++count;
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
