#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        int count1 = 0;
        int count2 = 0;

        for (auto& num : nums)
        {
            if (num < target)
                ++count1;
            else if (num == target)
                ++count2;
        }

        vector<int> out;
        for (int i = 0; i < count2; ++i)
            out.push_back(count1 + i);

        return out;
    }

    vector<int> getAverages(vector<int>& nums, int k)
    {
        int length = nums.size();
        if (length < k * 2 + 1)
            return vector<int>(length, -1);

        vector<int> out;
        long long tmp = 0;

        for (int i = 0; i < k; ++i)
            out.push_back(-1);

        for (int i = 0; i < length; ++i)
        {
            tmp += nums[i];
            if (k * 2 <= i)
            {
                out.push_back(tmp / (k * 2 + 1));
                tmp -= nums[i - k * 2];
            }
        }

        for (int i = 0; i < k; ++i)
            out.push_back(-1);

        return out;
    }

    int minimumDeletions(vector<int>& nums)
    {
        int min_index = 0;
        int max_index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[max_index] < nums[i])
                max_index = i;

            if (nums[i] < nums[min_index])
                min_index = i;
        }

        int tmp1 = nums.size() - min(min_index, max_index);
        int tmp2 = max(min_index, max_index) + 1;
        int tmp3 = min(min_index, max_index) + 1 + nums.size() - max(min_index, max_index);

        return min(tmp1, min(tmp2, tmp3));
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> colors = {1,2,5,2,3};
    int target = 2;
    vector<int> out = s.targetIndices(colors, target);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    vector<int> out = s.getAverages(nums, k);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << s.minimumDeletions(nums) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
