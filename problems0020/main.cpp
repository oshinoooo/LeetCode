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
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            if (c == '{'|| c == '[' || c == '(')
                stk.push(c);
            else {
                if (stk.empty())
                    return false;

                if ((c == '}' && stk.top() == '{') ||
                    (c == ']' && stk.top() == '[') ||
                    (c == ')' && stk.top() == '('))
                    stk.pop();
                else
                    return false;
            }
        }

        return stk.empty();
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    cout << "---------------------" << endl;
    return 0;
}
