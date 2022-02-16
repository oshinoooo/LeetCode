#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countQuadruplets(vector<int>& nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size() - 3; ++i)
        {
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                for (int k = j + 1; k < nums.size() - 1; ++k)
                {
                    for (int l = k + 1; l < nums.size(); ++l)
                    {
                        if (nums[i] + nums[j] + nums[k] == nums[l])
                            ++count;
                    }
                }
            }
        }

        return count;
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        int ret = 0;
        int max_attack = 0;

        for (int i = 0; i < properties.size(); ++i)
        {
            if (properties[i][0] > max_attack)
                max_attack = properties[i][0];
        }

        for (int i = 0; i < properties.size(); ++i)
        {
            int tmp_max = properties[i][0] > properties[i][1] ? properties[i][0] : properties[i][1];
//            if (tmp_max < max_min && i != max_min_index)
            if (tmp_max < max_min)
                ++ret;
        }

        return ret;
    }
};

void test1()
{
    cout << "-----------------------" << endl;
    Solution s;
    vector<int> nums = {28, 8, 49, 85, 37, 90, 20, 8};
    cout << s.countQuadruplets(nums) << endl;
    cout << "-----------------------" << endl;
}

void test2()
{
    cout << "-----------------------" << endl;
    Solution s;
    vector<vector<int>> properties = {{1, 5}, {10, 4}, {4, 3}};
    cout << s.numberOfWeakCharacters(properties) << endl;
    cout << "-----------------------" << endl;
}

void test3()
{
    cout << "-----------------------" << endl;
    Solution s;
    cout << "-----------------------" << endl;
}

void test4()
{
    cout << "-----------------------" << endl;
    Solution s;
    cout << "-----------------------" << endl;
}

int main()
{
    cout << "-----------------------" << endl;
//    test1();
    test2();
//    test3();
//    test4();
    cout << "-----------------------" << endl;
    return 0;
}
