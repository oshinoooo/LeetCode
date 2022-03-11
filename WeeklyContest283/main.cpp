#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

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

void test1() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.cellsInRange("K1:L2");
    for (auto num : out)
        cout << num << " ";
    cout << endl;
}

void test2() {
    cout << "---------------------" << endl;
    Solution s;
    cout << "" << endl;
}

void test3() {
    cout << "---------------------" << endl;
    Solution s;
    cout << "" << endl;
}

void test4() {
    cout << "---------------------" << endl;
    Solution s;
    cout << "" << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
