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

        bool first_row = false;
        for (int i = 0; i < n; ++i)
        {
            if (matrix[0][i] == 0)
            {
                first_row = true;
                break;
            }
        }

        bool first_cal = false;
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                first_cal = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for (int i = 1; i < n; ++i)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 0; j < m; ++j)
                    matrix[j][i] = 0;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }

        if (first_cal)
        {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }

        if (first_row)
        {
            for (int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        }
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

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
