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

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < m; ++l) {
                        if (matrix[l][k] != 1) {
                            break;
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> matrix = {"10100","10111","11111","10010"};
    cout << s.maximalRectangle(matrix) << endl;
    cout << "---------------------" << endl;
    return 0;
}
