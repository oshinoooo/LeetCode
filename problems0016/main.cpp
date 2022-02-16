#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int threeSumClosest1(vector<int>& nums, int target)
    {
        int min_dis = INT_MAX;
        int closest_sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    int distance = abs(sum - target);
                    if (distance < min_dis)
                    {
                        closest_sum = sum;
                        min_dis = distance;
                    }
                }
            }
        }
        return closest_sum;
    }

    int threeSumClosest2(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;

                if (abs(sum - target) < abs(closest_sum - target))
                    closest_sum = sum;

                if (sum > target)
                {
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k])
                        --k0;
                    k = k0;
                }
                else
                {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j])
                        ++j0;
                    j = j0;
                }
            }
        }
        return closest_sum;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0, 0, 0};
    int target = 1;
//    cout << s.threeSumClosest1(nums, target) << endl;
    cout << s.threeSumClosest2(nums, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
