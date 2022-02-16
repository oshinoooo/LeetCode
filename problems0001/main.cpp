#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum1(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
                return {it->second, i};
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> out = s.twoSum(nums, target);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
