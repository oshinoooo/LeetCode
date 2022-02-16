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
    int dominantIndex(vector<int>& nums) {
        int maxNumIndex = 0;
        bool flag = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[maxNumIndex] < nums[i] * 2) {
                flag = false;
                if (nums[maxNumIndex] * 2 <= nums[i])
                    flag = true;
                if (nums[maxNumIndex] < nums[i])
                    maxNumIndex = i;
            }
        }

        return flag ? maxNumIndex : -1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {60,48,80,80,6,59,24,55,57,57,
                        32,16,5,35,17,26,73,39,65,39,
                        55,80,77,67,26,70,16,34,9,46,
                        86,47,24,29,90,93,31,0,56,25,
                        40,35,90,22,1,46,67,44,25,73};
    cout << s.dominantIndex(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
