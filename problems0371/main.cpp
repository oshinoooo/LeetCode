#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << s.getSum(10, 12) << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
