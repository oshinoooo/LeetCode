#include <iostream>
#include <vector>
#include<bitset>

using namespace std;


const int num = 32;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t out = 0;
        for (int i = 0; i < 32 && n > 0; ++i)
        {
            out = out | (n & 1) << (31 - i);
            n >>= 1;
        }
        return out;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    cout << (bitset<num>)s.reverseBits(43261596) << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
