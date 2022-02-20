#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; ++i) {
            int subSize = n - i * 2 - 1;
            for (int j = i; j < i + subSize; ++j) {
                int next = matrix[i][j];
                swap(next, matrix[j][n - 1 - i]);
                swap(next, matrix[n - 1 - i][n - 1 - j]);
                swap(next, matrix[n - 1 - j][i]);
                swap(next, matrix[i][j]);
            }
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,0,1,2}, {3,4,5,6}};
    for (auto mat : matrix) {
        for (auto m : mat)
            cout << m << " ";
        cout << endl;
    }

    Solution s;
    s.rotate(matrix);
    cout << "---------------------" << endl;
    for (auto mat : matrix) {
        for (auto m : mat)
            cout << m << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
