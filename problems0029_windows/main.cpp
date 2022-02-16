#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;

        return find(abs((long long)dividend), abs((long long)divisor)) * sign;
    }

private:
    long long find(long long dividend, long long divisor)
    {
        if (dividend < divisor)
            return 0;
        if (dividend == divisor)
            return 1;

        long long times = 1;
        long long pre_times;
        long long tmp = divisor;
        long long pre_tmp;

        while (dividend > tmp)
        {
            pre_times = times;
            times += times;
            pre_tmp = tmp;
            tmp += tmp;
        }

        return pre_times + find(dividend - pre_tmp, divisor);
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    cout << s.divide(-2147483648, 1) << endl;
    cout << "---------------" << endl;
    return 0;
}
