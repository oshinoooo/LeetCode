#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head <= tail) {
            int mid = head + (tail - head) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                head = mid + 1;
            else
                tail = mid - 1;
        }

        return -1;
    }

    int lowerBound(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head <= tail) {
            int mid = head + (tail - head) / 2;
            if (nums[mid] < target)
                head = mid + 1;
            else
                tail = mid - 1;
        }

        return head;
    }

    int upperBound(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head <= tail) {
            int mid = head + (tail - head) / 2;
            if (nums[mid] <= target)
                head = mid + 1;
            else
                tail = mid - 1;
        }

        return head;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 8, 9};

    cout << s.binarySearch(nums, 7) << endl;
    cout << "---------------------" << endl;

    cout << s.lowerBound(nums, 7) << endl;
    cout << "---------------------" << endl;

    cout << s.upperBound(nums, 7) << endl;
    cout << "---------------------" << endl;
    return 0;
}
