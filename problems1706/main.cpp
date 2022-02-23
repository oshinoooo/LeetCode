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
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> out(n, -1);

        for (int j = 0; j < n; ++j) {
            int column = j;

            for (auto &row : grid) {
                int oldDirection = row[column];
                column += oldDirection;
                int newDirection = row[column];

                if (column < 0 || n <= column || newDirection != oldDirection) {
                    column = -1;
                    break;
                }
            }

            if (0 <= column)
                out[j] = column;
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{ 1,  1,  1, -1, -1},
                                { 1,  1,  1, -1, -1},
                                {-1, -1, -1,  1,  1},
                                { 1,  1,  1,  1, -1},
                                {-1, -1, -1, -1, -1}};
    vector<int> out = s.findBall(grid);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
