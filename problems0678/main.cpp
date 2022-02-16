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
    bool checkValidString1(string s) {
        stack<char> stk1;
        stack<char> stk2;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stk1.push(i);
            else if (s[i] == '*')
                stk2.push(i);
            else if (!stk1.empty())
                stk1.pop();
            else if (!stk2.empty())
                stk2.pop();
            else
                return false;
        }

        while (!stk1.empty() && !stk2.empty() && stk1.top() < stk2.top()) {
            stk1.pop();
            stk2.pop();
        }

        return stk1.empty();
    }

    bool checkValidString(string s) {
        int minCount = 0;
        int maxCount = 0;

        for (const char& c : s) {
            if (c == '(') {
                ++minCount;
                ++maxCount;
            }
            else if (c == ')') {
                --minCount;
                --maxCount;
                if (maxCount < 0)
                    return false;
            }
            else {
                minCount = max(minCount - 1, 0);
                ++maxCount;
            }
        }

        return minCount <= 0;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;
    cout << "---------------------" << endl;
    return 0;
}
