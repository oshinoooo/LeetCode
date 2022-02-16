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
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    bool canCross = false;
                    int tmp = countLands(grid, directions, i, j, canCross);
                    if (!canCross)
                        count += tmp;
                }
            }
        }

        return count;
    }

private:
    int countLands(vector<vector<int>>& grid, const vector<vector<int>>& directions, int x, int y, bool& canCross) {
        int count = 1;

        for (const auto& direction : directions) {
            int nextX = x + direction[0];
            int nextY = y + direction[1];
            if (nextX < 0 || grid.size() <= nextX || nextY < 0 || grid[0].size() <= nextY)
                canCross = true;
            else if (grid[nextX][nextY] == 1) {
                grid[nextX][nextY] = 0;
                count += countLands(grid, directions, nextX, nextY, canCross);
            }
        }

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << s.numEnclaves(grid)<< endl;
    cout << "---------------------" << endl;
    return 0;
}
