#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>
#include <ctime>
#include <list>

using namespace std;

class Solution
{
public:
    Solution(vector<int>& nums)
    {
        srand(time(0));
        m_nums = nums;
    }

    vector<int> reset()
    {
        return m_nums;
    }

    vector<int> shuffle1()
    {
        vector<int> out;
        list<int> tmp(m_nums.begin(), m_nums.end());

        while (!tmp.empty())
        {
            int index = rand() % tmp.size();
            auto it = tmp.begin();
            advance(it, index);
            out.push_back(*it);
            tmp.erase(it);
        }

        return out;
    }

    vector<int> shuffle()
    {
        vector<int> nums = m_nums;
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i], nums[j]);
        }
        return nums;
    }

private:
    vector<int> m_nums;
};

int main()
{
    cout << "---------------------" << endl;
    vector<int> nums = {1, 2, 3};
    Solution s(nums);

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    for (auto num : s.shuffle())
        cout << num << " ";
    cout << endl;

    cout << "---------------------" << endl;
    return 0;
}
