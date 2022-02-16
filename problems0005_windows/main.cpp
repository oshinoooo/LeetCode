#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = search(s, i, i);
            auto [left2, right2] = search(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    pair<int, int> search(string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
             --left;
             ++right;
        }
        return {left + 1, right - 1};
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    string in = "babad";
    cout << s.longestPalindrome(in) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
