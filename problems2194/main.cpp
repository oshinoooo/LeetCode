#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        int n = s.size();

        char colStart;
        char colEnd;
        int rowStart;
        int rowEnd;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ':') {
                colStart = s[0];
                colEnd = s[i + 1];
                rowStart = stoi(s.substr(1, i));
                rowEnd = stoi(s.substr(i + 2, n - i - 2));
                break;
            }
        }

        vector<string> out;
        for (int i = colStart; i <= colEnd; ++i) {
            for (int j = rowStart; j <= rowEnd; ++j) {
                string tmp;
                tmp.push_back(i);
                tmp += to_string(j);
                out.push_back(tmp);
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.cellsInRange("K1:L2");
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}