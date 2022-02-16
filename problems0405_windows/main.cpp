#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";

        string hex;
        for (int i = 7; i >= 0; --i)
        {
            int tmp_nu = (num >> (4 * i)) & 0x0000000f;
            if (tmp_nu != 0 || hex.size() != 0)
            {
                if (tmp_nu <= 9)
                    hex.push_back(tmp_nu + '0');
                else
                    hex.push_back(tmp_nu - 10 + 'a');
            }
        }

        return hex;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    cout << s.toHex(0x000fffff) << endl;
    cout << "---------------" << endl;
    return 0;
}
