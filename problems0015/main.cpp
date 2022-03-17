#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> out;
        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int head = i + 1;
            int tail = n - 1;

            while (head < tail) {
                if (head != i + 1 && nums[head - 1] == nums[head]) {
                    ++head;
                    continue;
                }

                int sum = nums[i] + nums[head] + nums[tail];
                if (sum < 0)
                    ++head;
                else if (sum == 0)
                    out.push_back({nums[i], nums[head++], nums[tail]});
                else
                    --tail;
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> out = s.threeSum(nums);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
