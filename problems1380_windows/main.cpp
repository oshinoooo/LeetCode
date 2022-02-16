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
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> minNum(m, INT_MAX);
        vector<int> maxNum(n, INT_MIN);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minNum[i] = min(minNum[i], matrix[i][j]);
                maxNum[j] = max(maxNum[j], matrix[i][j]);
            }
        }

        vector<int> out;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (minNum[i] == maxNum[j])
                    out.push_back(matrix[i][j]);
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<int> out = s.luckyNumbers(matrix);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
