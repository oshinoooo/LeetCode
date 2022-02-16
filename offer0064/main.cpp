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
    int sumNums(int n)
    {
        n && (n += sumNums(n - 1));
        return n;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.sumNums(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
