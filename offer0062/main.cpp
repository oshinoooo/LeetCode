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
#include <list>

using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        int position = lastRemaining(n - 1, m);
        return (m + position) % n;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.lastRemaining(5, 3) << endl;
    cout << "---------------------" << endl;
    return 0;
}
