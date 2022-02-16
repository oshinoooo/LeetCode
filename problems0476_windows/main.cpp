#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i) {
            if (num >= (1 << i)) {
                highbit = i;
            }
            else {
                break;
            }
        }
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        return num ^ mask;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.findComplement(5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
