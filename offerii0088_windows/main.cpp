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
    int minCostClimbingStairs(vector<int>& cost) {
        int pre = cost[0];
        int cur = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int tmp = min(pre, cur) + cost[i];
            pre = cur;
            cur = tmp;
        }
        return min(pre, cur);
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> cost = {10, 15, 20};
    cout << s.minCostClimbingStairs(cost) << endl;
    cout << "---------------------" << endl;
    return 0;
}
