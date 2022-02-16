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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = m * n;

        int x = 0;
        int y = 0;

        vector<vector<bool>> flag(m, vector<bool>(n, true));
        int direction = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> out;

        while (out.size() < sum) {
            out.push_back(matrix[x][y]);
            flag[x][y] = false;

            int nextX = x + directions[direction].first;
            int nextY = y + directions[direction].second;
            if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && flag[nextX][nextY]) {
                x = nextX;
                y = nextY;
            }
            else {
                direction = (direction + 1) % 4;
                x = x + directions[direction].first;;
                y = y + directions[direction].second;;
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{0, 0, 0}, {4, 5, 6}, {7, 8, 9}};
    vector<int> out = s.spiralOrder(matrix);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
