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
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& num :nums) {
            ++m[num];
        }

        for (auto& num : m) {
            if (num.second == 1) {
                return num.first;
            }
        }

        return -1;
    }

    int singleNumber(vector<int>& nums) {
        int out = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;

            for (int num: nums) {
                total += ((num >> i) & 1);
            }

            if (total % 3) {
                out |= (1 << i);
            }
        }
        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-2,-2,1,1,4,1,4,4,-4,-2};
    cout << s.singleNumber(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
