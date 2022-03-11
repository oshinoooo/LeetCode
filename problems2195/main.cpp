#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimalKSum1(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        long long cur = 1;
        long long sum = 0;
        int cnt = 0;

        while (cnt < k) {
            if (!s.count(cur)) {
                sum += cur;
                ++cnt;
            }
            ++cur;
        }

        return sum;
    }

    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);

        long long cur = 1;
        long long sum = 0;
        int index = 0;
        int count = 0;

        while (count < k) {
            if (index != 0 && nums[index - 1] == nums[index]) {
                ++index;
                continue;
            }

            if (cur == nums[index])
                ++index;
            else {
                sum += cur;
                ++count;
            }
            ++cur;
        }

        return sum;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {96,44,99,25,61,84,88,18,19,33,60,86,52,19,32,47,35,50,94,17,29,98,22,21,72,100,40,84};
    int k = 35;
    cout << s.minimalKSum(nums, k) << endl;
    cout << "--------------------" << endl;
    return 0;
}
