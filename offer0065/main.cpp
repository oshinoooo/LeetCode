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
    int add(int a, int b)
    {
        while(b != 0)
        {
            int carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.add(1, 2) << endl;
    cout << "---------------------" << endl;
    return 0;
}
