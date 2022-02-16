#include "TryAgain.h"

void TryAgain::bubble_sort(vector<int>& nums) {
    int length = nums.size();
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (nums[j + 1] < nums[j])
                swap(nums[j + 1], nums[j]);
        }
    }
}

void TryAgain::quick_sort(vector<int>& nums, int left, int right) {
    if (right <= left)
        return;

    int mid = nums[left];
    int tmpLeft = left;
    int tmpRight = right;

    while (tmpLeft < tmpRight) {
        while (tmpLeft < tmpRight && mid <= nums[tmpRight])
            --tmpRight;
        nums[tmpLeft] = nums[tmpRight];

        while (tmpLeft < tmpRight && nums[tmpLeft] <= mid)
            ++tmpLeft;
        nums[tmpRight] = nums[tmpLeft];
    }
    nums[tmpLeft] = mid;

    quick_sort(nums, left, tmpLeft - 1);
    quick_sort(nums, tmpLeft + 1, right);
}

void TryAgain::select_sort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        int minIndex = nums.size() - 1;
        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] < nums[minIndex])
                minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}

void TryAgain::insert_sort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] < nums[j]) {
                for (int k = j; k < i; ++k) {
                    swap(nums[i], nums[k]);
                }
            }
        }
    }
}

void TryAgain::merge_sort(vector<int>& nums, int left, int right) {
    if (left == right)
        return;

    int mid = (left + right) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);

    vector<int> tmp1(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> tmp2(nums.begin() + mid + 1, nums.begin() + right + 1);

    int ptr1 = 0;
    int ptr2 = 0;

    for (int i = left; i <= right; ++i) {
        if (ptr1 < tmp1.size() && ptr2 < tmp2.size()) {
            if (tmp1[ptr1] < tmp2[ptr2])
                nums[i] = tmp1[ptr1++];
            else
                nums[i] = tmp2[ptr2++];
        }
        else if (ptr1 < tmp1.size())
            nums[i] = tmp1[ptr1++];
        else if (ptr2 < tmp2.size())
            nums[i] = tmp2[ptr2++];
    }
}
