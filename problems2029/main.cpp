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
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int val: stones) {
            int type = val % 3;
            if (type == 0)
                ++cnt0;
            else if (type == 1)
                ++cnt1;
            else
                ++cnt2;
        }

        if (cnt0 % 2 == 0)
            return cnt1 >= 1 && cnt2 >= 1;
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> stones = {2, 1};
    cout << s.stoneGameIX(stones) << endl;
    cout << "---------------------" << endl;
    return 0;
}
