#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ret = 0;

        while (x != 0)
        {
            if (ret > 214748364 || ret < -214748364)
                return 0;
            else if (ret ==  214748364 && (x % 10 > 7))
                return 0;
            else if (ret == -214748364 && (x % 10 < -8))
                return 0;
            else
            {
                ret = ret * 10 + x % 10;
                x /= 10;
            }
        }

        return ret;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    int in = -123;
    cout << s.reverse(in) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
