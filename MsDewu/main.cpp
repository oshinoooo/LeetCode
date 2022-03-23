#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                string tmpWord;
                if (DFS(board, visited, word, i, j, tmpWord)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool DFS(const vector<vector<char>> &board,
             vector<vector<bool>> &visited,
             const string& word,
             int x,
             int y,
             string& tmp) {
        if (tmp.size() > word.size()) {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        if (x < 0 || m <= x || y < 0 || n <= y) {
            return false;
        }

        if (visited[x][y]) {
            return false;
        }

        tmp.push_back(board[x][y]);
        visited[x][y] = true;

        if (tmp == word) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];
            if (DFS(board, visited, word, nextX, nextY, tmp)) {
                return true;
            }
        }

        visited[x][y] = false;

        tmp.pop_back();

        return false;
    }

private:
    vector<vector<int>> directions;
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<vector<char>> board = {{'a', 'b'}, {'d', 'c'}};
    string word = "abcd";
    cout << s.exist(board, word) << endl;
    cout << "--------------------" << endl;
    return 0;
}