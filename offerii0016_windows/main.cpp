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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(176, -1);
        int max_length = 0;
        int start = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (start <= count[s[i]])
                start = count[s[i]] + 1;

            max_length = max(max_length, i - start + 1);
            count[s[i]] = i;
        }

        return max_length;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    cout << "---------------------" << endl;
    return 0;
}
