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
#include <ctime>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> out;
        vector<int> pre = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            int head = intervals[i][0];
            int tail = intervals[i][1];

            if (head <= pre[1])
                pre[1] = max(pre[1], tail);
            else {
                out.push_back(pre);
                pre = intervals[i];
            }
        }
        out.push_back(pre);

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> out = s.merge(intervals);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}