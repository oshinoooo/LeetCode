#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<int, int> chars;
        int ptr1 = 0;
        int count = 0;
        int max_length = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!chars.count(s[i]) || chars[s[i]] < ptr1)
            {
                chars[s[i]] = i;
                ++count;
            }
            else
            {
                ptr1 = chars[s[i]] + 1;
                chars[s[i]] = i;
                count = i - ptr1 + 1;
            }
            if (max_length < count)
                max_length = count;
        }
        return max_length;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.lengthOfLongestSubstring("aabaab!bb") << endl;
    cout << "---------------------" << endl;
    return 0;
}
