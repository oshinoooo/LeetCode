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
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int pre = 0;
        int cur = 1;
        for (int i = 2; i <= n; ++i) {
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
    cout << s.fib(45) << endl;
    cout << "---------------------" << endl;
    return 0;
}
