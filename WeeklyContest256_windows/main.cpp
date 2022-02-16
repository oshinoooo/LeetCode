#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution1
{
public:
    int minimumDifference(vector<int>& nums, int k)
    {
        if (nums.empty() || k == 0 || k == 1)
            return 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 0; j < nums.size() - 1 - i; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    int tmpNumber = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = tmpNumber;
                }
            }
        }
        for (auto num : nums)
            cout << num << "";
        cout << endl;

        vector<int> tmp;
        for (int i = 0; i < nums.size() - k + 1; ++i)
            tmp.push_back(nums[i + k - 1] - nums[i]);

        int min = tmp[0];
        for (auto t : tmp)
        {
            if (t < min)
                min = t;
        }

        return min;
    }
};

class Solution2
{
public:
    string kthLargestNumber(vector<string>& nums, int k)
    {
        if (nums.empty() || k == 0)
            return 0;

        Qsort(nums, 0, nums.size() - 1);

        for (auto num : nums)
            cout << num << endl;

        return nums[nums.size() - k];
    }

private:
    bool compare(string& str1, string& str2)
    {
        if (str1.size() > str2.size())
            return false;
        else if (str1.size() < str2.size())
            return true;
        else
        {
            for (int i = 0; i < str1.size(); ++i)
            {
                if (str1[i] > str2[i])
                    return false;
                else if (str1[i] < str2[i])
                    return true;
            }
            return true;
        }
    }

    void Qsort(vector<string>& nums, int low, int high)
    {
        if (high <= low)
            return;

        int i = low;
        int j = high + 1;
        string key = nums[low];

        while (true)
        {
            while (compare(nums[++i], key))
            {
                if (i == high)
                    break;
            }

            while (compare(key, nums[--j]))
            {
                if (j == low)
                    break;
            }

            if (i >= j)
                break;

            nums[i].swap(nums[j]);
        }
        nums[low].swap(nums[j]);
        Qsort(nums, low, j - 1);
        Qsort(nums, j + 1, high);
    }
};

class Solution3
{
public:
    int minSessions(vector<int>& tasks, int sessionTime)
    {
        return 2;
    }
};

class Solution4
{
public:
    int minSessions(vector<int>& tasks, int sessionTime)
    {

    }
};

void test_solution1()
{
    cout << "------------------" << endl;
    Solution1 s;
    vector<int> in = {4, 3, 5, 6, 1, 2, 9};
    cout << s.minimumDifference(in, 3) << endl;
    cout << "------------------" << endl;
}

void test_solution2()
{
    cout << "------------------" << endl;
    Solution2 s;
    vector<string> nums = {"41727","99579","78727"};
    int k = 2;
    cout << s.kthLargestNumber(nums, k) << endl;
    cout << "------------------" << endl;
}

void test_solution3()
{
    cout << "------------------" << endl;
    Solution3 s;
    vector<int> in = {1, 2, 3, 4};
    cout << s.minSessions(in, 5) << endl;
    cout << "------------------" << endl;
}

void test_solution4()
{
    cout << "------------------" << endl;
    Solution4 s;
    cout << "------------------" << endl;
}

int main()
{
    cout << "------------------" << endl;
//    test_solution1();
    test_solution2();
//    test_solution3();
//    test_solution4();
    cout << "------------------" << endl;
    return 0;
}
