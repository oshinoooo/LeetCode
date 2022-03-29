#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> out;

        int n = nums.size();
        map<int, int> m;

        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];

            if (k - 1 <= i) {
                out.push_back(m.rbegin()->first);
                if (!--m[nums[i - k + 1]])
                    m.erase(nums[i - k + 1]);
            }
        }

        return out;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;


        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> out = s.maxSlidingWindow(nums, 3);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}