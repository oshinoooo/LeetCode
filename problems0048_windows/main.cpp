#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate1(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        vector<int> tmp;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                tmp.push_back(matrix[i][j]);
        }

        for (int j = 0; j < n; ++j)
        {
            for (int i = n - 1; i >= 0; --i)
            {
                matrix[i][j] = tmp.back();
                tmp.pop_back();
            }
        }
    }

    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < (n + 1) / 2; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

int main()
{
    cout << "---------------------" << endl;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto mat : matrix)
    {
        for (auto m : mat)
            cout  << m << " ";
        cout << endl;
    }
    //      "---------------------"
    Solution s;
    s.rotate(matrix);
    cout << "---------------------" << endl;
    for (auto mat : matrix)
    {
        for (auto m : mat)
            cout  << m << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
