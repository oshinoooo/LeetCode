#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<pair<int, bool>>> matrix2(m, vector<pair<int, bool>>(n, {0, true}));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                matrix2[i][j].first = matrix[i][j];
        }

        int cur_row = 0;
        int cur_cal = 0;
        int destination_row = m / 2;
        int destination_cal = n / 2;
        vector<int> out;

        while (matrix2[destination_row][destination_cal].second)
        {
            while (cur_cal < n && matrix2[cur_row][cur_cal].second)
            {
                out.push_back(matrix2[cur_row][cur_cal].first);
                matrix2[cur_row][cur_cal].second = false;
                ++cur_cal;
            }
            --cur_cal;
            ++cur_row;

            while (cur_row < m && matrix2[cur_row][cur_cal].second)
            {
                out.push_back(matrix2[cur_row][cur_cal].first);
                matrix2[cur_row][cur_cal].second = false;
                ++cur_row;
            }
            --cur_row;
            --cur_cal;

            while (-1 < cur_cal && matrix2[cur_row][cur_cal].second)
            {
                out.push_back(matrix2[cur_row][cur_cal].first);
                matrix2[cur_row][cur_cal].second = false;
                --cur_cal;
            }
            ++cur_cal;
            --cur_row;

            while (-1 < cur_row && matrix2[cur_row][cur_cal].second)
            {
                out.push_back(matrix2[cur_row][cur_cal].first);
                matrix2[cur_row][cur_cal].second = false;
                --cur_row;
            }
            ++cur_row;
            ++cur_cal;
        }

        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> out = s.spiralOrder(matrix);
    for (auto ou : out)
        cout << ou << endl;
    cout << "-------------------------" << endl;
    return 0;
}
