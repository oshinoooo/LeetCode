#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> out;
        for (int i = 0; i < nums1.size(); ++i)
        {
            bool start = false;
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (!start && nums1[i] == nums2[j])
                    start = true;
                if (start && nums1[i] < nums2[j])
                {
                    out.push_back(nums2[j]);
                    break;
                }
            }

            if (out.size() == i)
                out.push_back(-1);
        }
        return out;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, int> hash;
        stack<int> sta;
        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            while (!sta.empty() && sta.top() <= nums2[i])
                sta.pop();
            if (sta.empty())
                hash[nums2[i]] = -1;
            else
                hash[nums2[i]] = sta.top();
            sta.push(nums2[i]);
        }

        vector<int> out;
        for (auto num : nums1)
            out.push_back(hash[num]);
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> out = s.nextGreaterElement(nums1, nums2);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
