#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> grid(m, vector<bool>(n, true));
        queue<pair<int, int>> que;
        que.push({0, 0});
        int count = 0;

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if (!grid[x][y])
                continue;

            if (smaller(x, y, k)) {
                grid[x][y] = false;
                ++count;
                if (x + 1 < m)
                    que.push({x + 1, y});
                if (y + 1 < n)
                    que.push({x, y + 1});
            }
        }

        return count;
    }

private:
    bool smaller(int x, int y, int k) {
        int tmp = 0;

        while (x) {
            tmp += x % 10;
            x /= 10;
        }

        while (y) {
            tmp += y % 10;
            y /= 10;
        }

        return tmp <= k;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.movingCount(3, 2, 17) << endl;
    cout << "--------------------" << endl;
    return 0;
}
