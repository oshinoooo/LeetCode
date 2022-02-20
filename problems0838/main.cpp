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
    string pushDominoes(string dominoes) {
        int length = dominoes.size();

        queue<int> que;
        vector<int> state(length, 0);
        for (int i = 0; i < length; ++i) {
            if (dominoes[i] != 'L') {
                que.push(i);
                state[i] = -1;
            }
            if (dominoes[i] != 'R') {
                que.push(i);
                state[i] = 1;
            }
        }

        while (!que.empty()) {
            int index = que.front();
            que.pop();

            if (dominoes[index] == 'R') {
                state =
            }
        }

        return dominoes;
    }

    string pushDominoes2(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, - 1);
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                q.emplace(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }

        string out(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                out[i] = f;
                int ni = (f == 'L') ? (i - 1) : (i + 1);
                if (ni >= 0 and ni < n) {
                    int t = time[i];
                    if (time[ni] == -1) {
                        q.emplace(ni);
                        time[ni] = t + 1;
                        force[ni].push_back(f);
                    }
                    else if(time[ni] == t + 1)
                        force[ni].push_back(f);
                }
            }
        }
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.pushDominoes("RR.L") << endl;
    cout << "---------------------" << endl;
    return 0;
}
