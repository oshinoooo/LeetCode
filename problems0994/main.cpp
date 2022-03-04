#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> times(m, vector<int>(n, INT_MAX));
        const vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    times[i][j] = 0;
                else if (grid[i][j] == 2) {
                    vector<vector<int>> tmpGrid = grid;
                    queue<vector<int>> que;
                    que.push({i, j, 0});

                    while (!que.empty()) {
                        vector<int> node = que.front();
                        que.pop();

                        int x = node[0];
                        int y = node[1];
                        int t = node[2];

                        times[x][y] = min(times[x][y], t);

                        for (int k = 0; k < directions.size(); ++k) {
                            int nextX = directions[k][0] + x;
                            int nextY = directions[k][1] + y;

                            if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && tmpGrid[nextX][nextY] == 1) {
                                tmpGrid[nextX][nextY] = 2;
                                que.push({nextX, nextY, t + 1});
                            }
                        }
                    }
                }
            }
        }

        int minTime = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minTime = max(minTime, times[i][j]);
            }
        }

        return minTime == INT_MAX ? -1 : minTime;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << s.orangesRotting(grid) << endl;
    cout << "--------------------" << endl;
    return 0;
}
