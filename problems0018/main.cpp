#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4) return {};

        set<vector<int>> tmp_out;
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                for (int k = j + 1; k < nums.size() - 1; ++k)
                {
                    for (int l = k + 1; l < nums.size(); ++l)
                    {
                        long long tmp = nums[i];
                        tmp += nums[j];
                        tmp += nums[k];
                        tmp += nums[l];
                        if (tmp == target)
                            tmp_out.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }

        vector<vector<int>> out;
        for (auto tmp : tmp_out)
            out.push_back(tmp);
        return out;
    }

    vector<vector<int>> fourSum2(vector<int>& nums, int target)
    {
        int length = nums.size();
        if (length < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;

        for (int i = 0; i < length - 3; ++i)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < length - 2; ++j)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;

                for (int k = j + 1; k < length - 1; ++k)
                {
                    if (k > j + 1 && nums[k - 1] == nums[k])
                        continue;

                    for (int l = k + 1; l < length; ++l)
                    {
                        if (l > k + 1 && nums[l - 1] == nums[l])
                            continue;

                        long long tmp = nums[i];
                        tmp += nums[j];
                        tmp += nums[k];
                        tmp += nums[l];
                        if (tmp == target)
                            out.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }

        return out;
    }

    vector<vector<int>> fourSum3(vector<int>& nums, int target)
    {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;

        int length = nums.size();
        for (int i = 0; i < length - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            long long sum = nums[i];
            sum += nums[i + 1];
            sum += nums[i + 2];
            sum += nums[i + 3];
            if (sum > target)
                break;

            sum = nums[i];
            sum += nums[length - 3];
            sum += nums[length - 2];
            sum += nums[length - 1];
            if (sum < target)
                continue;

            for (int j = i + 1; j < length - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                sum = nums[i];
                sum += nums[j];
                sum += nums[j + 1];
                sum += nums[j + 2];
                if (sum > target)
                    break;

                sum = nums[i];
                sum += nums[j];
                sum += nums[length - 2];
                sum += nums[length - 1];
                if (sum < target)
                    continue;

                int left = j + 1, right = length - 1;
                while (left < right)
                {
                    sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];
                    if (sum == target)
                    {
                        out.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;

                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return out;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    vector<int> nums = {2, 2, 2, 2, 2};
    int target = 8;

//    vector<vector<int>> out = s.fourSum(nums, target);
//    vector<vector<int>> out = s.fourSum2(nums, target);
    vector<vector<int>> out = s.fourSum3(nums, target);

    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    std::cout << "---------------" << std::endl;
    return 0;
}
