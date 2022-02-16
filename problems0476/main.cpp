#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findComplement1(int num)
    {
        string binary;
        while (num > 0)
        {
            binary.insert(0, to_string(num & 1));
            num >>= 1;
        }

        int out = 0;
        bool prefix = true;
        for (auto bin : binary)
        {
            if (bin == '1' && prefix)
                continue;
            else if (bin == '0')
            {
                prefix = false;
                out <<= 1;
                out += 1;
            }
            else
                out <<= 1;
        }
        return out;
    }

    int findComplement(int num)
    {
        int tmp = 0x40000000;
        int out = 0;
        bool prefix = true;
        while (tmp > 0)
        {
            if ((num & tmp) == 0 && !prefix)
                out += tmp;
            else if ((num & tmp) != 0 && prefix)
                prefix = false;
            tmp >>= 1;
        }
        return out;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    cout << s.findComplement(5) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
