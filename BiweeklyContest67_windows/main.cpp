#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        vector<int> out(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); ++i)
        {
            int min_index = 0;
            for (int j = 0; j < out.size(); ++j)
            {
                if (out[j] < out[min_index])
                    min_index = j;
            }

            if (out[min_index] < nums[i])
            {
                out.erase(out.begin() + min_index);
                out.push_back(nums[i]);
            }
        }

        return out;
    }

    vector<int> goodDaysToRobBank(vector<int>& security, int time)
    {
        if (time == 1)
            return {};

        int length = security.size();
        vector<int> dp1 = {0, 1};
        for (int i = 2; i < length; ++i)
        {
            if (security[i - 1] <= security[i - 2])
                dp1.push_back(dp1.back() + 1);
            else
                dp1.push_back(1);
        }

        vector<int> dp2 = {0, 1};
        for (int i = length - 3; 0 <= i; --i)
        {
            if (security[i + 1] <= security[i + 2])
                dp2.push_back(dp2.back() + 1);
            else
                dp2.push_back(1);
        }
//        reverse(dp2.begin(), dp2.end());

        vector<int> out;
        for (int i = 0; i < length; ++i)
        {
            if (time <= dp1[i] && time <= dp2[length - i - 1])
//            if (time <= dp1[i] && time <= dp2[i])
                out.push_back(i);
        }

        return out;
    }

    int maximumDetonation(vector<vector<int>>& bombs)
    {
        return 0;
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2,1,3,3};
    int k = 2;
    vector<int> out = s.maxSubsequence(nums, k);
    for (auto& num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> security = {1,2,5,4,1,0,2,4,5,3,1,2,4,3,2,4,8};
    int time = 2;
    vector<int> out = s.goodDaysToRobBank(security, time);
    for (auto& num : out)
        cout << num << " ";
    cout << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> bombs = {};
    cout << s.maximumDetonation(bombs) << endl;
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
