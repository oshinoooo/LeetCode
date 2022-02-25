#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void bubble(vector<int>& nums) {

    }

    void quick(vector<int>& nums, int head, int tail) {

    }

    void merge(vector<int>& nums, int head, int tail) {
        if (tail <= head)
            return;

        int mid = (head + tail) / 2;
        merge(nums, head, mid);
        merge(nums, mid + 1, tail);

        vector<int> temp(nums.begin() + head, nums.begin() + mid + 1);
        int ptr1 = 0;
        int ptr2 = mid + 1;
        int curr = head;

        while (ptr1 < temp.size() || ptr2 <= tail) {
            if (ptr1 < temp.size() && ptr2 <= tail) {
                if (temp[ptr1] < nums[ptr2])
                    nums[curr++] = temp[ptr1++];
                else
                    nums[curr++] = nums[ptr2++];
            }
            else if (ptr1 < temp.size())
                nums[curr++] = temp[ptr1++];
            else
                nums[curr++] = nums[ptr2++];
        }
    }

    void selection_sort(vector<int>& nums) {

    }

    void insertion_sort(vector<int>& nums) {

    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {5, 7, 0, 1, 9, 6, 3, 4, 8, 2};

//    s.bubble(nums);
//    s.quick(nums, 0, nums.size() - 1);
    s.merge(nums, 0, nums.size() - 1);
//    s.selection_sort(nums);
//    s.insertion_sort(nums);

    for (const int& num : nums)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
