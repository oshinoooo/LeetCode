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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> west(m, 0);
        vector<int> north(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                west[i] = max(west[i], grid[i][j]);
                north[j] = max(north[j], grid[i][j]);
            }
        }

        int sum = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                sum += min(west[i], north[j]) - grid[i][j];
        }

        return sum;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{3, 0, 8, 4},
                                {2, 4, 5, 7},
                                {9, 2, 6, 3},
                                {0, 3, 1, 0}};
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
    cout << "--------------------" << endl;
    return 0;
}
