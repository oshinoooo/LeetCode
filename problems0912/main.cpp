#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>
#include <time.h>

using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    vector<int> sortArray(vector<int>& nums) {
//        quickSort(nums, 0, nums.size() - 1);
//        mergeSort(nums, 0, nums.size() - 1);
        heapSort(nums);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (right <= left)
            return;

        int index = rand() % (right - left + 1) + left;
        swap(nums[index], nums[left]);
        int pivot = nums[left];
        int tmpLeft = left;
        int tmpRight = right;

        while (tmpLeft < tmpRight) {
            while (tmpLeft < tmpRight && pivot <= nums[tmpRight])
                --tmpRight;
            nums[tmpLeft] = nums[tmpRight];

            while (tmpLeft < tmpRight && nums[tmpLeft] <= pivot)
                ++tmpLeft;
            nums[tmpRight] = nums[tmpLeft];
        }
        nums[tmpLeft] = pivot;

        quickSort(nums, left, tmpLeft - 1);
        quickSort(nums, tmpLeft + 1, right);
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (right <= left)
            return;

        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int ptr1 = left;
        int ptr2 = mid + 1;
        vector<int> tmp;

        while (ptr1 <= mid || ptr2 <= right) {
            if (ptr1 <= mid && ptr2 <= right) {
                if (nums[ptr1] < nums[ptr2])
                    tmp.push_back(nums[ptr1++]);
                else
                    tmp.push_back(nums[ptr2++]);
            }
            else if (ptr1 <= mid)
                tmp.push_back(nums[ptr1++]);
            else
                tmp.push_back(nums[ptr2++]);
        }

        for (int i = left; i <= right; ++i)
            nums[i] = tmp[i - left];
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

    void heapSort(vector<int>& nums) {
        int size = nums.size();

        for(int i = size / 2 - 1; 0 <= i; --i)
            adjust(nums, size, i);

        for(int i = size - 1; 1 <= i; i--) {
            swap(nums[0], nums[i]);
            adjust(nums, i, 0);
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};
    vector<int> out = s.sortArray(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
