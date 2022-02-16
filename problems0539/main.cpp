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

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (1440 < timePoints.size())
            return 0;

        vector<int> times;
        for (auto& timePoint : timePoints)
            times.push_back((timePoint[0] - '0') * 600 + (timePoint[1] - '0') * 60 + (timePoint[3] - '0') * 10 + (timePoint[4] - '0'));

        sort(times.begin(), times.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < times.size(); ++i)
            minDiff = min(minDiff, times[i] - times[i - 1]);

        minDiff = min(minDiff, times.front() + 24 * 60 - times.back());

        return minDiff;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> timePoints = {"23:59","00:00"};
    cout << s.findMinDifference(timePoints) << endl;
    cout << "---------------------" << endl;
    return 0;
}
