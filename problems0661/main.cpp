#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> out(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = 0, sum = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            num++;
                            sum += img[x][y];
                        }
                    }
                }
                out[i][j] = sum / num;
            }
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    vector<vector<int>> outs = s.imageSmoother(img);
    for (auto out : outs) {
        for (auto num : out)
            cout << num << " ";
        cout << endl;
    }
    cout << "--------------------" << endl;
    return 0;
}
