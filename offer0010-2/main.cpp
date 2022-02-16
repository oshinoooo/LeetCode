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
    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int pre = 1;
        int cur = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = cur;
            cur = (cur + pre) % 1000000007;
            pre = tmp;
        }

        return cur;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.numWays(45) << endl;
    cout << "---------------------" << endl;
    return 0;
}
