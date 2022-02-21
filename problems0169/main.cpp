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

    // 优先队列
    int majorityElement3(vector<int>& nums) {
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

    // 投票
    int majorityElement4(vector<int>& nums) {
        int candidate = -1;
        int count = 0;

        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }

        return candidate;
    }

    // 分治
    int majorityElement(vector<int>& nums) {
        return myMajorityElement(nums, 0, nums.size() - 1);
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

    int myMajorityElement(vector<int>& nums, int head, int tail) {
        if (head == tail)
            return nums[head];

        int mid = (head + tail) / 2;
        int left_majority = myMajorityElement(nums, head, mid);
        int right_majority = myMajorityElement(nums, mid + 1, tail);

        if ((tail - head + 1) / 2 < count(nums, left_majority, head, tail))
            return left_majority;

        if ((tail - head + 1) / 2 < count(nums, right_majority, head, tail))
            return right_majority;

        return -1;
    }

    int count(vector<int>& nums, int target, int head, int tail) {
        int count = 0;
        for (int i = head; i <= tail; ++i)
            if (nums[i] == target)
                ++count;
        return count;
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
