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
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> out(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    out[i][j] = 0;
                    que.emplace(i, j);
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            auto position = que.front();
            que.pop();

            for (auto& dir : dirs) {
                int x = position.first + dir[0];
                int y = position.second + dir[1];

                if (0 <= x && x < m && 0 <= y && y < n && out[x][y] == -1) {
                    out[x][y] = out[position.first][position.second] + 1;
                    que.emplace(x, y);
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> isWater = {{0, 0, 0, 0, 0, 0, 1, 0},
                                   {0, 1, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 1, 0},
                                   {0, 0, 1, 0, 0, 0, 0, 0}};
    vector<vector<int>> out = s.highestPeak(isWater);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
