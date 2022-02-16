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

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>> available(m, vector<bool>(n, true));
        enum diretions {LEFT, RIGHT, UP, DOWN};
        diretions dir = RIGHT;
        vector<int> out;

        int i = 0;
        int j = 0;
        while (0 <= i && i < m && 0 <= j && j < n && available[i][j])
        {
            out.push_back(matrix[i][j]);
            available[i][j] = false;
            if (dir == RIGHT)
            {
                if (n <= ++j || !available[i][j])
                {
                    --j;
                    ++i;
                    dir = DOWN;
                }
            }
            else if (dir == DOWN)
            {
                if (m <= ++i || !available[i][j])
                {
                    --i;
                    --j;
                    dir = LEFT;
                }
            }
            else if (dir == LEFT)
            {
                if (--j < 0 || !available[i][j])
                {
                    ++j;
                    --i;
                    dir = UP;
                }
            }
            else if (dir == UP)
            {
                if (--i < 0 || !available[i][j])
                {
                    ++i;
                    ++j;
                    dir = RIGHT;
                }
            }
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> matrix = {{1}};
    vector<int> out = s.spiralOrder(matrix);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
