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
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> out;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int k = nums.size() - 1;
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                if (j != i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }

                while (j < k && -nums[i] < nums[j] + nums[k]) {
                    --k;
                }

                if (j == k) {
                    break;
                }
                else if (nums[i] + nums[j] + nums[k] == 0) {
                    out.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> out = s.threeSum(nums);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
