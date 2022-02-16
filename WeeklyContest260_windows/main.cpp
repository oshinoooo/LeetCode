#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int>& nums)
    {
        int max = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int dif = nums[j] - nums[i];
                if (dif > max)
                    max = dif;
            }
        }

        if (max) return max;
        else return -1;
    }

    long long gridGame(vector<vector<int>>& grid)
    {

    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {7, 1, 5, 4};
    cout << s.maximumDifference(nums) << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{1}};
    cout << s.gridGame(grid) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    cout << "---------------------" << endl;
    return 0;
}
