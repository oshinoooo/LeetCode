#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] <= target && target <= matrix[i][matrix[0].size() - 1])
            {
                for (int j = 0; j < matrix[0].size(); ++j)
                {
                    if (matrix[i][j] == target)
                        return true;

                    if (matrix[i][j] > target)
                        return false;
                }
            }
        }
        return false;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 3;
    cout << s.searchMatrix(matrix, target) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
