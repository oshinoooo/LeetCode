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
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
        matrix[0][1] = 1;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j)
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }

        return matrix.back().back();
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    cout << "--------------------" << endl;
    return 0;
}
