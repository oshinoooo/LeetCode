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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int ptr3 = m + n - 1;

        while (0 <= ptr1 || 0 <= ptr2) {
            if (0 <= ptr1 && 0 <= ptr2) {
                if (nums1[ptr1] < nums2[ptr2])
                    nums1[ptr3--] = nums2[ptr2--];
                else
                    nums1[ptr3--] = nums1[ptr1--];
            }
            else if (0 <= ptr1)
                nums1[ptr3--] = nums1[ptr1--];
            else
                nums1[ptr3--] = nums2[ptr2--];
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    s.merge(nums1, m, nums2, n);
    for (auto num : nums1)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
