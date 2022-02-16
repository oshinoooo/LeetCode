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

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum.resize(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row1][col2 + 1] - prefix_sum[row2 + 1][col1] + prefix_sum[row1][col1];
    }

private:
    vector<vector<int>> prefix_sum;
};

int main() {
    cout << "---------------------" << endl;
    vector<vector<int>> matrix = {{3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5}, {4,1,0,1,7}, {1,0,3,0,5}};
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2,1,4,3) << endl;
    cout << numMatrix.sumRegion(1,1,2,2) << endl;
    cout << numMatrix.sumRegion(1,2,2,4) << endl;
    cout << "---------------------" << endl;
    return 0;
}
