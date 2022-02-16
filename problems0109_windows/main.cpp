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
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000")
            return 0;

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;

        int minStep = INT_MAX;
        unordered_set<string> visited;
        queue<pair<string, int>> que;
        que.emplace("0000", 0);

        while (!que.empty()) {
            auto [code, step] = que.front();
            que.pop();

            if (code == target)
                minStep = min(minStep, step);
            else if (!visited.count(code)) {
                visited.emplace(code);
                if (!dead.count(code)) {
                    for (int i = 0; i < code.size(); ++i) {
                        string nextCode = code;

                        nextCode[i] += 1;
                        if ('9' < nextCode[i])
                            nextCode[i] -= 10;
                        que.emplace(nextCode, step + 1);

                        nextCode[i] -= 2;
                        if (nextCode[i] < '0')
                            nextCode[i] += 10;
                        que.emplace(nextCode, step + 1);
                    }
                }
            }
        }

        if (minStep == INT_MAX)
            return -1;
        return minStep;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    cout << s.openLock(deadends, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
