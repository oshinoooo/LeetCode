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
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
//        quickSort(nums, 0, nums.size() - 1);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int head, int tail) {
        if (tail <= head)
            return;

        int index = rand() % (tail - head + 1) + head;
        swap(nums[head], nums[index]);

        int pivot = nums[head];
        int tmpHead = head;
        int tmpTail = tail;

        while (tmpHead < tmpTail) {
            while (tmpHead < tmpTail && pivot <= nums[tmpTail])
                --tmpTail;
            nums[tmpHead] = nums[tmpTail];

            while (tmpHead < tmpTail && nums[tmpHead] <= pivot)
                ++tmpHead;
            nums[tmpTail] = nums[tmpHead];
        }

        nums[tmpHead] = pivot;

        quickSort(nums, head, tmpHead - 1);
        quickSort(nums, tmpHead + 1, tail);
    }

    void mergeSort(vector<int>& nums, int head, int tail) {
        if (tail <= head)
            return;

        int mid = (head + tail) / 2;
        mergeSort(nums, head, mid);
        mergeSort(nums, mid + 1, tail);

        vector<int>tmp(nums.begin() + head, nums.begin() + mid + 1);

        int ptr1 = 0;
        int ptr2 = mid + 1;
        for (int i = head; i <= tail; ++i) {
            if (ptr1 < tmp.size() && ptr2 <= tail) {
                if (tmp[ptr1] < nums[ptr2])
                    nums[i] = tmp[ptr1++];
                else
                    nums[i] = nums[ptr2++];
            }
            else if (ptr1 < tmp.size())
                nums[i] = tmp[ptr1++];
            else
                nums[i] = nums[ptr2++];
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
