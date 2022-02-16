#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> board2(m, vector<bool>(n, true));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (exist_recursive(board, board2, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }

private:
    bool exist_recursive(vector<vector<char>>& board, vector<vector<bool>>& board2, int x, int y, string& word, int cur)
    {
        if (board[x][y] != word[cur])
            return false;

        if (cur == word.size() - 1)
            return true;

        board2[x][y] = false;

        if (y + 1 < board[0].size() && board2[x][y + 1])
        {
            if (exist_recursive(board, board2, x, y + 1, word, cur + 1))
                return true;
        }

        if (0 <= y - 1 && board2[x][y - 1])
        {
            if (exist_recursive(board, board2, x, y - 1, word, cur + 1))
                return true;
        }

        if (x + 1 < board.size() && board2[x + 1][y])
        {
            if (exist_recursive(board, board2, x + 1, y, word, cur + 1))
                return true;
        }

        if (0 <= x - 1 && board2[x - 1][y])
        {
            if (exist_recursive(board, board2, x - 1, y, word, cur + 1))
                return true;
        }

        board2[x][y] = true;
        return false;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<char>> board = {{'A', 'A', 'A', 'A', 'A', 'A'},
                                  {'A', 'A', 'A', 'A', 'A', 'A'},
                                  {'A', 'A', 'A', 'A', 'A', 'A'},
                                  {'A', 'A', 'A', 'A', 'A', 'A'},
                                  {'A', 'A', 'A', 'A', 'A', 'A'},
                                  {'A', 'A', 'A', 'A', 'A', 'A'}};

    string word = "AAAAAAB";
    cout << s.exist(board, word) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
