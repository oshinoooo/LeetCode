#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    {
        if (original.size() != m * n)
            return {};

        vector<vector<int>> out(m, vector<int>(n, 0));

        int loop_count = 0;
        for (int i = 0; i < original.size(); ++i)
        {
            out[loop_count][i % n] = original[i];
            if (i % n == n - 1)
                ++loop_count;
        }

        return out;
    }

    int numOfPairs(vector<string>& nums, string target)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i != j && nums[i] + nums[j] == target)
                    ++count;
            }
        }

        return count;
    }
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    vector<vector<int>> out = s.construct2DArray(original, m, n);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
}

void test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> nums = {"777","7","77","77"};
    string target = "7777";
    cout << s.numOfPairs(nums, target) << endl;
}

int main()
{
    test1();
    test2();
    cout << "---------------------" << endl;
    return 0;
}
