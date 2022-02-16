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
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int ptr1 = matrix.size() - 1;
        int ptr2 = 0;

        while (0 <= ptr1 && ptr2 < matrix[0].size()) {
            if (matrix[ptr1][ptr2] == target) {
                return true;
            }
            else if (matrix[ptr1][ptr2] < target) {
                ++ptr2;
            }
            else {
                --ptr1;
            }
        }

        return false;
    }

    bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1;
        int j = 0;

        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) {
                i--;
            }
            else if(matrix[i][j] < target) {
                j++;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {  {1,   4,  7, 11, 15},
                                    {2,   5,  8, 12, 19},
                                    {3,   6,  9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}};
    int target = 20;
    cout << s.findNumberIn2DArray(matrix, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
