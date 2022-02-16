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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        stack<int> s;

        for (int i = 0; i < temperatures.size(); ++i) {
            if (s.empty() || temperatures[i] <= temperatures[s.top()]) {
                s.push(i);
            }
            else {
                while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                    out[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> out = s.dailyTemperatures(temperatures);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
