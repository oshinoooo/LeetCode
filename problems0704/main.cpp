#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head <= tail) {
            int mid = (head + tail) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                head = mid + 1;
            else
                tail = mid - 1;
        }

        return -1;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {-1,0,2,5,9,12};
    int target = 2;
    cout << s.search(nums, target) << endl;
    cout << "--------------------" << endl;
    return 0;
}