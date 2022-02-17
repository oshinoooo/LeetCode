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
    Solution() {
        count = 0;
        directions = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    }

    double knightProbability1(int n, int k, int row, int column) {
        myKnightProbability(n, k, row, column);
        return count / pow(8, k);
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int step = 0; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (step == 0)
                        dp[step][i][j] = 1;
                    else {
                        for (auto & dir : directions) {
                            int ni = i + dir[0], nj = j + dir[1];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n)
                                dp[step][i][j] += dp[step - 1][ni][nj] / 8;
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }

private:
    void myKnightProbability(int n, int k, int x, int y) {
        if (0 <= x && x < n && 0 <= y && y < n) {
            if (k == 0) {
                ++count;
                return;
            }
        }
        else
            return;

        for (int i = 0; i < directions.size(); ++i) {
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];
            myKnightProbability(n, k - 1, nextX, nextY);
        }
    }

private:
    double count;
    vector<vector<int>> directions;
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.knightProbability(3, 2, 0, 0) << endl;
    cout << "---------------------" << endl;
    return 0;
}
