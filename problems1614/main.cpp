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
    int maxDepth(string s) {
        int max_depth = 0;
        int cur_depth = 0;
        for (auto& c : s) {
            if (c == '(')
                max_depth = max(max_depth, ++cur_depth);
            else if (c == ')')
                --cur_depth;
        }
        return max_depth;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    cout << "---------------------" << endl;
    return 0;
}
