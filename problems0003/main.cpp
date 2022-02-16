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
#include <ctime>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;

        int start = 0;
        vector<int> position(200, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (position[s[i]] < start)
                maxLength = max(maxLength, i - start + 1);
            else
                start = position[s[i]] + 1;
            position[s[i]] = i;
        }

        return maxLength;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << "---------------------" << endl;
    return 0;
}
