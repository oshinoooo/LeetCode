#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& nums, const int& target) {
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
    cout << "---------------------" << endl;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 4;
    Solution solution;
    cout << solution.binarySearch(nums, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
