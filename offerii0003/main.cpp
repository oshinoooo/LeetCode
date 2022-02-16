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
    vector<int> countBits(int n) {
        vector<int> out(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            out[i] = out[i & (i - 1)] + 1;
        }
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> out = s.countBits(5);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
