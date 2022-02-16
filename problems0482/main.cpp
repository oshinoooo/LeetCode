#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string out;
        int count = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '-')
                continue;

            if (count == k)
            {
                out.push_back('-');
                count = 0;
            }

            out.push_back(toupper(s[i]));
            ++count;
        }

        reverse(out.begin(), out.end());
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.licenseKeyFormatting("----------------", 100) << endl;
    cout << "---------------------" << endl;
    return 0;
}
