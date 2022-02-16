#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {  { 1,  4,  7, 11, 15},
                                    { 2,  5,  8, 12, 19},
                                    { 3,  6,  9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}};
    int target = 5;
    cout << s.searchMatrix(matrix, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
