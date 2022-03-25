#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // BSF
    int numIslands1(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> que;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    grid[i][j] = '0';
                    que.emplace(i, j);

                    while (!que.empty()) {
                        auto [x, y] = que.front();
                        que.pop();

                        if (x + 1 < grid.size()    && grid[x + 1][y] == '1') {
                            que.emplace(x + 1, y);
                            grid[x + 1][y] = '0';
                        }

                        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
                            que.emplace(x, y + 1);
                            grid[x][y + 1] = '0';
                        }

                        if (0 <= x - 1             && grid[x - 1][y] == '1') {
                            que.emplace(x - 1, y);
                            grid[x - 1][y] = '0';
                        }

                        if (0 <= y - 1             && grid[x][y - 1] == '1') {
                            que.emplace(x, y - 1);
                            grid[x][y - 1] = '0';
                        }
                    }
                }
            }
        }

        return count;
    }

    // BSF
    int numIslands3(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> que;
        const vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    grid[i][j] = '0';
                    que.emplace(i, j);

                    while (!que.empty()) {
                        auto [x, y] = que.front();
                        que.pop();

                        for (int k = 0; k < directions.size(); ++k) {
                            int nextX = directions[k][0] + x;
                            int nextY = directions[k][1] + y;

                            if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && grid[nextX][nextY] == '1') {
                                grid[nextX][nextY] = '0';
                                que.push({nextX, nextY});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }

    // DFS
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    grid[i][j] = '0';
                    myNumIslands(grid, i, j);
                }
            }
        }

        return count;
    }

private:
    void myNumIslands(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < directions.size(); ++i) {
            int nextX = directions[i][0] + x;
            int nextY = directions[i][1] + y;
            if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && grid[nextX][nextY] == '1') {
                grid[nextX][nextY] = '0';
                myNumIslands(grid, nextX, nextY);
            }
        }
    }

private:
    vector<vector<int>> directions;
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};
    cout << s.numIslands(grid) << endl;
    cout << "---------------------" << endl;
    return 0;
}
