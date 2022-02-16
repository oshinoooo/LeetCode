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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        stack<int> stk;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                out[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {73,74,75,71,69,72,76,73};
    vector<int> out = s.dailyTemperatures(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
