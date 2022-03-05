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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> out;

        out = security;

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> security = {5,3,3,3,5,6,2};
    int time = 2;
    vector<int> out = s.goodDaysToRobBank(security, time);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
