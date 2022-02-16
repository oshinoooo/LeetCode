#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1;

        long abs_n = n;
        abs_n = abs_n > 0 ? abs_n : -abs_n;
        double ret;

        if (abs_n % 2 == 1)
        {
            ret = myPow(x, abs_n / 2);
            ret *= ret * x;
        }
        else
        {
            ret = myPow(x, abs_n / 2);
            ret *= ret;
        }

        return n > 0 ? ret : 1 / ret;
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;
    double x = 2.00000;
    int n = -2;
    cout << s.myPow(x, n) << endl;
    cout << "----------------"<< endl;
    return 0;
}
