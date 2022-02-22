#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int maxLength = 0;

        for (const int& num : s) {
            if (!s.count(num - 1)) {
                int currentNum = num;
                int tmpLength = 1;

                while (s.count(currentNum + 1)) {
                    currentNum += 1;
                    tmpLength += 1;
                }

                maxLength = max(maxLength, tmpLength);
            }
        }

        return maxLength;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

//        sort(nums.begin(), nums.end());
        quickSort(nums, 0, nums.size() - 1);

        int maxLength = 0;

        int tmpLength = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] + 1 == nums[i])
                ++tmpLength;
            else if (nums[i - 1] == nums[i])
                continue;
            else {
                maxLength = max(maxLength, tmpLength);
                tmpLength = 1;
            }
        }

        return max(maxLength, tmpLength);
    }

private:
    void quickSort(vector<int>& nums, int head, int tail) {
        if (tail <= head)
            return;

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
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
