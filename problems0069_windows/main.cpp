#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int out = 0;
        long long pow = 0;
        while (pow < x)
        {
            pow = out;
            pow *= pow;
            ++out;
        }

        if (pow != x)
            --out;

        return out;
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;
    cout << s.mySqrt(4)<< endl;
    cout << "----------------"<< endl;
    return 0;
}
