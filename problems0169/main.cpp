#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <map>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    // 哈希表
    int majorityElement1(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
            ++m[nums[i]];

        for (auto [num, count] : m) {
            if (nums.size() / 2 < count)
                return num;
        }

        return -1;
    }

    // 快速排序
    int majorityElement2(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() / 2];
    }

    // 投票
    int majorityElement3(vector<int>& nums) {




        return 0;
    }

    // 优先队列
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        priority_queue<int> pq;

        for (int num : nums) {
            pq.push(num);
            if (nums.size() / 2 + 1 < pq.size())
                pq.pop();
        }

        return pq.top();
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
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2, 2, 3, 3, 3, 3, 2};
    cout << s.majorityElement(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
