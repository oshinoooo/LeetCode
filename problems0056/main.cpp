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
//        sort(intervals.begin(), intervals.end());
        quickSort(intervals, 0, intervals.size() - 1);

        vector<vector<int>> out;
        int tmpHead = intervals[0][0];
        int tmpTail = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (tmpTail < intervals[i][0]) {
                out.push_back({tmpHead, tmpTail});
                tmpHead = intervals[i][0];
                tmpTail = intervals[i][1];
            }
            else
                tmpTail = max(tmpTail, intervals[i][1]);
        }

        out.push_back({tmpHead, tmpTail});

        return out;
    }

private:
    void quickSort(vector<vector<int>>& intervals, int head, int tail) {
        if (tail <= head)
            return;

        int index = rand() % (tail - head + 1) + head;
        swap(intervals[index], intervals[head]);
        vector<int> pivot = intervals[head];

        int tmpHead = head;
        int tmpTail = tail;

        while (tmpHead < tmpTail) {
            while (tmpHead < tmpTail && pivot[0] <= intervals[tmpTail][0])
                --tmpTail;
            intervals[tmpHead] = intervals[tmpTail];

            while (tmpHead < tmpTail && intervals[tmpHead][0] < pivot[0])
                ++tmpHead;
            intervals[tmpTail] = intervals[tmpHead];
        }

        intervals[tmpHead] = pivot;

        quickSort(intervals, head, tmpHead - 1);
        quickSort(intervals, tmpHead + 1, tail);
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
