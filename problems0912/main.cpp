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
        quickSort(nums, 0, nums.size() - 1);
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
