#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        double store1 = 0;
        double store2 = 0;

        int ptr1 = 0;
        int ptr2 = 0;

        for (int i = 0; i <= (m + n) / 2; ++i) {
            store1 = store2;
            if (ptr1 < m && ptr2 < n) {
                if (nums1[ptr1] < nums2[ptr2])
                    store2 = nums1[ptr1++];
                else
                    store2 = nums2[ptr2++];
            }
            else if (ptr1 < m)
                store2 = nums1[ptr1++];
            else if (ptr2 < n)
                store2 = nums2[ptr2++];
        }

        if ((m + n) % 2)
            return store2;
        return (store1 + store2) / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        double store1 = 0;
        double store2 = 0;

        int ptr1 = 0;
        int ptr2 = 0;

        for (int i = 0; i <= (m + n) / 2; ++i) {
            store1 = store2;
            if (ptr1 < m && ptr2 < n) {
                if (nums1[ptr1] < nums2[ptr2])
                    store2 = nums1[ptr1++];
                else
                    store2 = nums2[ptr2++];
            }
            else if (ptr1 < m)
                store2 = nums1[ptr1++];
            else
                store2 = nums2[ptr2++];
        }

        if ((m + n) % 2)
            return store2;
        return (store1 + store2) / 2;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    cout << "--------------------" << endl;
    return 0;
}
