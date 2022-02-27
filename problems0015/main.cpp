#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    vector<vector<int>> threeSum1(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        vector<vector<int>> out;
        for (int i = 0; i < size - 2; ++i) {
            if (0 < i && nums[i - 1] == nums[i])
                continue;

            int target = -nums[i];
            int ptr1 = i + 1;
            int ptr2 = size - 1;

            while (ptr1 < ptr2) {
                if (i + 1 < ptr1 & nums[ptr1] == nums[ptr1 - 1]) {
                    ++ptr1;
                    continue;
                }

                if (nums[ptr1] + nums[ptr2] == target)
                    out.push_back({nums[i], nums[ptr1++], nums[ptr2]});
                else if (nums[ptr1] + nums[ptr2] < target)
                    ++ptr1;
                else
                    --ptr2;
            }
        }

        return out;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int length = nums.size();

        vector<vector<int>> out;
        for (int i = 0; i < length - 2; ++i) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int target = -nums[i];
            int ptr1 = i + 1;
            int ptr2 = length - 1;

            while (ptr1 < ptr2) {
                if (ptr1 != i + 1 && nums[ptr1 - 1] == nums[ptr1]) {
                    ++ptr1;
                    continue;
                }

                if (nums[ptr1] + nums[ptr2] == target)
                    out.push_back({nums[i], nums[ptr1++], nums[ptr2]});
                else if (nums[ptr1] + nums[ptr2] < target)
                    ++ptr1;
                else
                    --ptr2;
            }
        }

        return out;
    }

private:
    void quickSort(vector<int>& nums, int head, int tail) {
        if (tail <= head)
            return;

        int index = rand() % (tail - head + 1) + head;
        swap(nums[index], nums[head]);
        int pivot = nums[head];

        int tmpHead = head;
        int tmpTail = tail;

        while (tmpHead < tmpTail) {
            while (pivot <= nums[tmpTail])
                --tmpTail;
            nums[tmpHead] = nums[tmpTail];

            while (nums[tmpHead] <= pivot)
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> out = s.threeSum(nums);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
