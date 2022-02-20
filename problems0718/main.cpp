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
    // 暴力
    int findLength1(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int maxLength = 0;

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                int length = 0;

                while (i + length < size1 &&
                       j + length < size2 &&
                       nums1[i + length] == nums2[j + length]) {
                    ++length;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }

    // 动态规划
    int findLength2(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int maxLength = 0;

        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i < size1 + 1; ++i) {
            for (int j = 1; j < size2 + 1; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }

    // 滑动窗口
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int maxLength = 0;

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                if (nums1[i] == nums2[j]) {
                    maxLength = max(maxLength, myFindLength(nums1, nums2, i, j));
                }
            }
        }

        return maxLength;
    }

private:
    int myFindLength(vector<int>& nums1, vector<int>& nums2, int ptr1, int ptr2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int maxLength = 0;

        while (ptr1 < size1 && ptr2 < size2 && nums1[ptr1++] == nums2[ptr2++]) {
            ++maxLength;
        }

        return maxLength;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {0,1,1,1,1};
    vector<int> nums2 = {1,0,1,0,1};
    cout << s.findLength(nums1, nums2) << endl;
    cout << "---------------------" << endl;
    return 0;
}
