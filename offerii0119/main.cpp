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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength = 0;
        for (auto num : s) {
            if (!s.count(num - 1)) {
                int count = 1;
                while (s.count(++num))
                    ++count;
                maxLength = max(maxLength, count);
            }
        }
        return maxLength;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> num = {1,2,0,1};
    cout << s.longestConsecutive(num) << endl;
    cout << "---------------------" << endl;
    return 0;
}
