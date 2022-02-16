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
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool>> board_available(m, vector<bool>(n, false));
        return my_movingCount(0, 0, k, board_available);
    }

private:
    int my_movingCount(int row, int col, int& k, vector<vector<bool>>& board_available)
    {
        if (row < 0 || col < 0 || board_available.size() <= row || board_available[0].size() <= col)
            return 0;

        if (board_available[row][col])
            return 0;

        int sum = 0;
        int tmp_row = row;
        while (0 < tmp_row)
        {
            sum += tmp_row % 10;
            tmp_row /= 10;
        }
        int tmp_col = col;
        while (0 < tmp_col)
        {
            sum += tmp_col % 10;
            tmp_col /= 10;
        }
        if (k < sum)
            return 0;

        board_available[row][col] = true;

        int ret = my_movingCount(row + 1, col, k, board_available) +
                  my_movingCount(row - 1, col, k, board_available) +
                  my_movingCount(row, col + 1, k, board_available) +
                  my_movingCount(row, col - 1, k, board_available) + 1;
        return ret;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
