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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxTimeIndex = 0;
        int maxTime = releaseTimes[0];

        for (int i = 1; i < releaseTimes.size(); ++i) {
            int curTime = releaseTimes[i] - releaseTimes[i - 1];
            if (maxTime < curTime || (maxTime == curTime && keysPressed[maxTimeIndex] < keysPressed[i])) {
                maxTimeIndex = i;
                maxTime = releaseTimes[i] - releaseTimes[i - 1];
            }
        }

        return keysPressed[maxTimeIndex];
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> releaseTimes = {9,29,49,50};
    string keysPressed = "cbcd";
    cout << s.slowestKey(releaseTimes, keysPressed) << endl;
    cout << "---------------------" << endl;
    return 0;
}
