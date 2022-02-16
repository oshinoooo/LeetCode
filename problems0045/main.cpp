#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int min_step = 0;
        int farthest = 0;
        int end = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (i <= farthest)
            {
                farthest = max(farthest, i + nums[i]);
                if (i == end)
                {
                    end = farthest;
                    ++min_step;
                }
            }
        }
        return min_step;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
