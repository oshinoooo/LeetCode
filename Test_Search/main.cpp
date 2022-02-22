#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch1(const vector<int>& nums, const int target) {
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

    int lowerBound1(const vector<int>& nums, const int target) {
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

    int upperBound1(const vector<int>& nums, const int target) {
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

    int binarySearch(const vector<int>& nums, const int target) {
        int n = nums.size();

        int ptr1 = 0;
        int ptr2 = n - 1;
        while (ptr1 <= ptr2) {
            int mid = (ptr1 + ptr2) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }

        return -1;
    }

    int lowerBound(const vector<int>& nums, const int target) {
        int n = nums.size();

        int ptr1 = 0;
        int ptr2 = n - 1;
        while (ptr1 <= ptr2) {
            int mid = (ptr1 + ptr2) / 2;

            if (nums[mid] == target)
                ptr2 = mid - 1;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }

        return ptr1;
    }

    int upperBound(const vector<int>& nums, const int target) {
        int n = nums.size();

        int ptr1 = 0;
        int ptr2 = n - 1;
        while (ptr1 <= ptr2) {
            int mid = (ptr1 + ptr2) / 2;

            if (nums[mid] == target)
                ptr1 = mid + 1;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }

        return ptr1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 8, 9, 10, 11};

    cout << s.binarySearch(nums, 7) << endl;
    cout << "---------------------" << endl;

    cout << s.lowerBound(nums, 7) << endl;
    cout << "---------------------" << endl;

    cout << s.upperBound(nums, 7) << endl;
    cout << "---------------------" << endl;
    return 0;
}
