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
    // DFS
    int numIslands1(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    DSF(grid, i, j);
                }
            }
        }

        return count;
    }

    // BSF
    int numIslands2(vector<vector<char>>& grid) {
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

    // DFS
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    DSF(grid, i, j);
                }
            }
        }

        return count;
    }

private:
    void DSF1(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';

        if (x + 1 < grid.size()    && grid[x + 1][y] == '1')
            DSF(grid, x + 1, y);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
            DSF(grid, x, y + 1);
        if (0 <= x - 1             && grid[x - 1][y] == '1')
            DSF(grid, x - 1, y);
        if (0 <= y - 1             && grid[x][y - 1] == '1')
            DSF(grid, x, y - 1);
    }

    void DSF(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';

        if (x + 1 < grid.size() && grid[x + 1][y] == '1')
            DSF(grid, x + 1, y);
        if (0 <= x - 1 && grid[x - 1][y] == '1')
            DSF(grid, x - 1, y);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
            DSF(grid, x, y + 1);
        if (0 <= y - 1 && grid[x][y - 1] == '1')
            DSF(grid, x, y - 1);
    }
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
