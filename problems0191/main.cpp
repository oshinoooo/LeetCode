#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n & 1 == 1)
                ++count;
            n >>= 1;
        }
        return count;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    uint32_t n = 15;
    cout << s.hammingWeight(n) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
