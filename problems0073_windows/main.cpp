#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; ++i)
        {
            if (matrix[0][i] == 0)

        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = true;
                    cal[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (row[i] || cal[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << "-------------------------" << endl;

    s.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << "-------------------------" << endl;
    return 0;
}
