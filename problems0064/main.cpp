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
    int minPathSum1(vector<vector<int>>& grid) {
        int minSum = INT_MAX;
        myMinPathSum(grid, 0, 0, 0, minSum);
        return minSum;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];

        for (int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i - 1];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }

        return grid.back().back();
    }

private:
    void myMinPathSum(const vector<vector<int>>& grid, int x, int y, int tmp, int& minSum) {
        int m = grid.size();
        int n = grid[0].size();

        if (x == m - 1 && y == n - 1) {
            minSum = min(minSum, tmp + grid[x][y]);
            return;
        }

        if (0 <= x && x < m && 0 <= y && y < n) {
            if (x < m - 1)
                myMinPathSum(grid, x + 1, y, tmp + grid[x][y], minSum);
            if (y < n - 1)
                myMinPathSum(grid, x, y + 1, tmp + grid[x][y], minSum);
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s.minPathSum(grid) << endl;
    cout << "---------------------" << endl;
    return 0;
}
