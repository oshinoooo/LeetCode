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
#include <ctime>

using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

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
        nums[tmpTail] = pivot;

        quickSort(nums, head, tmpTail - 1);
        quickSort(nums, tmpTail + 1, tail);
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << s.findKthLargest(nums, k) << endl;
    cout << "---------------------" << endl;
    return 0;
}
