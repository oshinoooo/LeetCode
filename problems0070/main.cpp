#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<long long> methods = {1, 2};
        for (int i = 2; i <= n; ++i)
            methods.push_back(methods[i - 1] + methods[i - 2]);
        return methods[n - 1];
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.climbStairs(1) << endl;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
