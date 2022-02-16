//
// Created by Youlong Liu on 1/21/22.
//

#include <iostream>
#include "Solution.h"

using namespace std;

void Solution::bubble_sort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (nums[j + 1] < nums[j])
                swap(nums[j + 1], nums[j]);
        }
    }
}

void Solution::quick_sort(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int pivot_position = quick_sort_recursive(nums, left, right);
        quick_sort(nums, left, pivot_position - 1);
        quick_sort(nums, pivot_position + 1, right);
    }
}

int Solution::quick_sort_recursive(vector<int>& nums, int left, int right)
{
    int pivot = nums[left];
    while (left < right)
    {
        while (left < right && pivot <= nums[right])
            --right;
        nums[left] = nums[right];

        while (left < right && nums[left] <= pivot)
            ++left;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void Solution::select_sort(vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int min_ind = i;
        for (int j = i; j < nums.size(); ++j)
        {
            if (nums[j] < nums[min_ind])
                min_ind = j;
        }
        swap(nums[min_ind], nums[i]);
    }
}

void Solution::insert_sort(vector<int>& nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] <= nums[j])
            {
                int cur = nums[i];
                for (int k = j; k <= i; ++k)
                    swap(nums[k], cur);
                break;
            }
        }
    }
}

void Solution::merge_sort(vector<int>& nums, int left, int right)
{
    if (left == right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);

    vector<int> tmp1(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> tmp2(nums.begin() + mid + 1, nums.begin() + right + 1);
    tmp1.push_back(INT_MAX);
    tmp2.push_back(INT_MAX);
    int ptr1 = 0;
    int ptr2 = 0;
    for (int i = left; i <= right; ++i)
    {
        if (tmp1[ptr1] < tmp2[ptr2])
        {
            nums[i] = tmp1[ptr1];
            ++ptr1;
        }
        else
        {
            nums[i] = tmp2[ptr2];
            ++ptr2;
        }
    }
}

void adjust(vector<int>& nums, int length, int index)
{
    int left  = 2 * index + 1;
    int right = 2 * index + 2;

    int maxIdx = index;

    if(left < length && nums[maxIdx] < nums[left])
        maxIdx = left;

    if(right < length && nums[maxIdx] < nums[right])
        maxIdx = right;

    if(maxIdx != index) {
        swap(nums[maxIdx], nums[index]);
        adjust(nums, length, maxIdx);
    }
}

void Solution::heap_sort(vector<int>& nums) {
    int size = nums.size();

    for(int i = size / 2 - 1; 0 <= i; --i)
        adjust(nums, size, i);

    for(int i = size - 1; 1 <= i; i--) {
        swap(nums[0], nums[i]);
        adjust(nums, i, 0);
    }
}

void Solution::shell_sort(vector<int>& nums) {
    int length = nums.size();

    for (int step = length / 2; 0 < step; step /= 2) {
        for (int i = 0; i < step; ++i) {
            for (int j = i + step; j < length; j = j + step) {
                if (nums[j - step] > nums[j]) {
                    for (int k = j; 0 <= k - step && nums[k - step] > nums[k]; k -= step)
                        swap(nums[k - step], nums[k]);
                }
            }
        }
    }
}
