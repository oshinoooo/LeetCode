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
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](vector<int> a, vector<int> b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        stack<int> stk;
        int out = 0;
        for (auto& property : properties) {
            while (!stk.empty() && stk.top() < property[1]) {
                stk.pop();
                ++out;
            }
            stk.push(property[1]);
        }

        return out;
    }

    int numberOfWeakCharacters2(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
        });

        int maxDef = 0;
        int ans = 0;
        for (auto & p : properties) {
            if (p[1] < maxDef) {
                ans++;
            } else {
                maxDef = p[1];
            }
        }
        return ans;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> properties = {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
    cout << s.numberOfWeakCharacters(properties) << endl;
    cout << "---------------------" << endl;
    return 0;
}
