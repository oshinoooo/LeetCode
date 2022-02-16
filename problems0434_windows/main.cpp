#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        if (s.empty())
            return 0;

        int count = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ' ' && s[i - 1] != ' ')
                ++count;
        }

        if (s[s.size() - 1] != ' ')
            ++count;

        return count;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    cout << s.countSegments("Hello, my name is John") << endl;
    cout << "-------------------------" << endl;
    return 0;
}
