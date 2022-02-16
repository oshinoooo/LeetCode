#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string forward;
        for (auto c : s)
        {
            if (isalnum(c))
                forward.push_back(tolower(c));
        }

        string reverse(forward.rbegin(), forward.rend());

        if (reverse == forward)
            return true;

        return false;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    cout << s.isPalindrome("   ###    $$$ abcd  DCBA   *** (()") << endl;
    cout << "-----------------------" << endl;
    return 0;
}
