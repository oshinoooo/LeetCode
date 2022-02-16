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
    string simplifyPath(string path) {
        stack<string> s;
        string tmp;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (!tmp.empty()) {
                    s.push(tmp);
                    tmp.clear();
                }
            }
            else {
                tmp.push_back(path[i]);
            }

            if (i == path.size() - 1 && !tmp.empty()) {
                s.push(tmp);
                tmp.clear();
            }
        }

        string out;
        int jump = 0;
        while (!s.empty()) {
            if (s.top() == ".") {
                s.pop();
            }
            else if (s.top() == "..") {
                s.pop();
                ++jump;
            }
            else {
                if (0 == jump) {
                    s.top() = "/" + s.top();
                    out.insert(out.begin(), s.top().begin(), s.top().end());
                }
                else {
                    --jump;
                }
                s.pop();
            }
        }

        if (out.empty()) {
            out = "/";
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.simplifyPath("/../") << endl;
    cout << "---------------------" << endl;
    return 0;
}
