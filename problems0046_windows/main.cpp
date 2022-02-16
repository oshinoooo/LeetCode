#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.empty()) return {};
        set<int> numbers;
        for (auto num : nums)
            numbers.insert(num);
        return recursive_permute(numbers);
    }

    vector<vector<int>> permute2(vector<int>& nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }

private:
    vector<vector<int>> recursive_permute(set<int>& nums) const
    {
        if (nums.size() == 1)
            return {{*nums.begin()}};

        vector<vector<int>> ret;
        for (auto num : nums)
        {
            set<int> next_nums = nums;
            next_nums.erase(num);

            vector<vector<int>> tmp_ret = recursive_permute(next_nums);
            for (auto& r : tmp_ret)
                r.push_back(num);

            ret.insert(ret.end(), tmp_ret.begin(), tmp_ret.end());
        }

        return ret;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len)
    {
        // 所有数都填完了
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }

        for (int i = first; i < len; ++i)
        {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
//    vector<vector<int>> out = s.permute(nums);
    vector<vector<int>> out = s.permute2(nums);

    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "----------------"<< endl;
    return 0;
}
