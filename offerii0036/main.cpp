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
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();

                if (token == "+")
                    s.push(num2 + num1);
                else if (token == "-")
                    s.push(num2 - num1);
                else if (token == "*")
                    s.push(num2 * num1);
                else if (token == "/")
                    s.push(num2 / num1);
            }
            else
                s.push(toInt(token));
        }

        return s.top();
    }

private:
    int toInt(string num) {
        int out = 0;
        int sign = 1;
        if (num[0] == '-')
            sign = -1;
        else if (num[0] == '+')
            sign = 1;
        else
            out = num[0] - '0';

        for (int i = 1; i < num.size(); ++i)
            out = (out * 10) + num[i] - '0';

        return out * sign;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> tokens = {"3","-4","+"};
    cout << s.evalRPN(tokens) << endl;
    cout << "---------------------" << endl;
    return 0;
}
