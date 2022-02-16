#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int end = m + n - 1;

        while (ptr1 >= 0 || ptr2 >= 0)
        {
            if (ptr1 < 0)
            {
                nums1[end] = nums2[ptr2];
                --ptr2;
            }
            else if (ptr2 < 0)
            {
                nums1[end] = nums1[ptr1];
                --ptr1;
            }
            else if (nums1[ptr1] > nums2[ptr2])
            {
                nums1[end] = nums1[ptr1];
                --ptr1;
            }
            else
            {
                nums1[end] = nums2[ptr2];
                --ptr2;
            }
            --end;
        }
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
//    s.merge1(nums1, m, nums2, n);
    s.merge2(nums1, m, nums2, n);

    for (auto num : nums1)
        cout << num << endl;
    cout << "----------------"<< endl;
    return 0;
}
