#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    }

    /*
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param word string字符串
 * @return bool布尔型
 */
    bool isCorrectCapitalization(string word) {
        if (word.empty())
            return false;

        if (word.size() == 1)
            return true;

        bool first = isupper(word[0]);

        if (first) {
            bool second = isupper(word[1]);

            if (second) {
                for (int i = 2; i < word.size(); ++i) {
                    if (islower(word[i]))
                        return false;
                }
            }
            else {
                for (int i = 2; i < word.size(); ++i) {
                    if (isupper(word[i]))
                        return false;
                }
            }
        }
        else {
            for (int i = 1; i < word.size(); ++i) {
                if (isupper(word[i]))
                    return false;
            }
        }

        return true;
    }

    /*
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param brackets string字符串
     * @return bool布尔型
     */
    bool isValid(string brackets) {
        // write code here
        stack<char> stk;

        for (int i = 0; i < brackets.size(); ++i) {
            if (brackets[i] == '[' || brackets[i] == '{' || brackets[i] == '(')
                stk.push(brackets[i]);
            else {
                if (!stk.empty()) {
                    if ((brackets[i] == ']' && stk.top() == '[') ||
                        (brackets[i] == '}' && stk.top() == '{') ||
                        (brackets[i] == ')' && stk.top() == '('))
                        stk.pop();
                }
                else
                    return false;
            }
        }

        return stk.empty();
    }

    int solve(vector<vector<int>>& matrix) {
        // write code here

        int m = matrix.size();
        int n = matrix[0].size();
        int tmpLength = 1;
        vector<vector<bool>> flags(m, vector<bool>(n, true));
        int maxLength = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                flags[i][j] = false;
                mySolve(matrix, i, j, tmpLength, flags, maxLength);
                flags[i][j] = true;
            }
        }

        return maxLength;
    }

private:
    void mySolve(vector<vector<int>>& matrix, int x, int y, int tmpLength, vector<vector<bool>>& flags, int& maxLength) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < directions.size(); ++i) {
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];

            if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n) {
                if (matrix[x][y] < matrix[nextX][nextY] && flags[nextX][nextY]) {
                    maxLength = max(maxLength, tmpLength + 1);
                    flags[nextX][nextY] = false;
                    mySolve(matrix, nextX, nextY, tmpLength + 1, flags, maxLength);
                    flags[nextX][nextY] = true;
                }
            }
        }
    }

private:
    vector<vector<int>> directions;
};

int main() {
    cout << "------------------------" << endl;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    cout << solution.solve(matrix) << endl;
    cout << "------------------------" << endl;
    return 0;
}
