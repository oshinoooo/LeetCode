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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int length = s.size();

        int prev = -1;
        vector<int> left(length);
        for (int i = 0; i < length; ++i) {
            if (s[i] == '|')
                prev = i;
            left[i] = prev;
        }

        prev = length;
        vector<int> right(length);
        for (int i = length - 1; 0 <= i; --i) {
            if (s[i] == '|')
                prev = i;
            right[i] = prev;
        }

        vector<int> count(length, 0);
        for (int i = 1; i < length; ++i) {
            count[i] = count[i - 1];
            if (s[i - 1] == '*')
                count[i] += 1;
        }

        int m = queries.size();
        vector<int> out(m);

        for (int i = 0; i < m; ++i) {
            int head = right[queries[i][0]];
            int tail = left[queries[i][1]];
            if (head < tail)
                out[i] = count[tail] - count[head];
            else
                out[i] = 0;
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    string str = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    vector<int> out = s.platesBetweenCandles(str, queries);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
