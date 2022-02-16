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
    vector<string> generateParenthesis1(int n) {
        vector<string> out;
        string tmp;
        myGenerateParenthesis(n, 0, tmp, out);
        return out;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> out;
        queue<tuple<string, int, int>> que;
        que.push({"", 0, 0});

        while (!que.empty()) {
            auto [str, left, right] = que.front();
            que.pop();

            if (str.size() == n * 2)
                out.push_back(str);
            else {
                if (left < n)
                    que.push({str + "(", left + 1, right});

                if (right < left)
                    que.push({str + ")", left, right + 1});
            }
        }

        return out;
    }

private:
    void myGenerateParenthesis(const int& n, int leftNum, string& tmp, vector<string>& out) {
        if (tmp.size() == n * 2) {
            out.push_back(tmp);
            return;
        }

        if (leftNum < n) {
            tmp.push_back('(');
            myGenerateParenthesis(n, leftNum + 1, tmp, out);
            tmp.pop_back();
        }

        if (tmp.size() - leftNum < leftNum) {
            tmp.push_back(')');
            myGenerateParenthesis(n, leftNum, tmp, out);
            tmp.pop_back();
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.generateParenthesis(3);
    for (auto num : out)
        cout << num << endl;
    cout << "---------------------" << endl;
    return 0;
}
