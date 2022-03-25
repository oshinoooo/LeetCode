#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        int start = 0;
        int maxLength = 0;
        vector<int> positions(250, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (positions[s[i]] < start)
                maxLength = max(maxLength, i - start + 1);
            else
                start = positions[s[i]] + 1;

            positions[s[i]] = i;
        }

        return maxLength;
    }

    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxLength = 0;
        vector<int> positions(250, -1);

        for (int i = 0; i < s.size(); ++i) {
            if (start <= positions[s[i]]) {
                start = positions[s[i]] + 1;
            }
            maxLength = max(maxLength, i - start + 1);
            positions[s[i]] = i;
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