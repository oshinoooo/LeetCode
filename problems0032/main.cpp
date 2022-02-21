#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (!stk.empty() && s[stk.top()] == '(' && s[i] == ')')
                stk.pop();
            else
                stk.push(i);
        }
        stk.push(s.size());

        int maxLength = 0;

        while (2 <= stk.size()) {
            int tail = stk.top();
            stk.pop();
            int head = stk.top();
            maxLength = max(maxLength, tail - head - 1);
        }

        maxLength = max(maxLength, stk.top());

        return maxLength;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.longestValidParentheses("(()") << endl;
    cout << "---------------------" << endl;
    return 0;
}
