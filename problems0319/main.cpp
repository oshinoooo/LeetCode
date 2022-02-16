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
    int bulbSwitch(int n)
    {
        return sqrt(n + 0.5);
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.bulbSwitch(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
