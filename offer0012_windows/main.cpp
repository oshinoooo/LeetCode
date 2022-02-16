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
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> board_available(m, vector<bool>(n, true));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (my_exist(board, word, i, j, board_available))
                    return true;
            }
        }

        return false;
    }

private:
    bool my_exist(vector<vector<char>>& board, string word, int row, int col, vector<vector<bool>>& board_available)
    {
        if (row < 0 || col < 0 || board.size() <= row || board[0].size() <= col)
            return false;
        if (!board_available[row][col] || board[row][col] != word[0])
            return false;
        if (word.size() == 1)
            return true;

        board_available[row][col] = false;

        if (my_exist(board, word.substr(1, word.size() - 1), row + 1, col, board_available) ||
            my_exist(board, word.substr(1, word.size() - 1), row - 1, col, board_available) ||
            my_exist(board, word.substr(1, word.size() - 1), row, col + 1, board_available) ||
            my_exist(board, word.substr(1, word.size() - 1), row, col - 1, board_available))
            return true;

        board_available[row][col] = true;
        return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << s.exist(board, word) << endl;
    cout << "---------------------" << endl;
    return 0;
}
