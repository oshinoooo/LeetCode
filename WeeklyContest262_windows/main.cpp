#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        map<int, int> m;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());

        for (int i = 0; i < nums1.size(); ++i)
        {
            if (i != 0 && nums1[i - 1] == nums1[i])
                continue;
            ++m[nums1[i]];
        }

        for (int i = 0; i < nums2.size(); ++i)
        {
            if (i != 0 && nums2[i - 1] == nums2[i])
                continue;
            ++m[nums2[i]];
        }

        for (int i = 0; i < nums3.size(); ++i)
        {
            if (i != 0 && nums3[i - 1] == nums3[i])
                continue;
            ++m[nums3[i]];
        }

        vector<int> out;
        for (auto num : m)
        {
            if (num.second > 1)
                out.push_back(num.first);
        }

        return out;
    }

    int minOperations(vector<vector<int>>& grid, int x)
    {
        vector<int> store;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
                store.push_back(grid[i][j]);
        }

        sort(store.begin(), store.end());

        int sub = store[0];
        for (auto& num : store)
            num -= sub;

        for (auto& num : store)
        {
            if (num % x != 0)
                return -1;
        }

        int mid = store[store.size() / 2];
        int count = 0;
        for (int i = 0; i < store.size(); ++i)
            count = count + (abs(store[i] - mid) / x);

        return count;
    }
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums1 = {1, 1, 3, 2};
    vector<int> nums2 = {2, 3};
    vector<int> nums3 = {3};
    vector<int> out = s.twoOutOfThree(nums1, nums2, nums3);
    for (auto ou : out)
        cout << ou << " ";
    cout << endl;
}

void test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;
    cout << s.minOperations(grid, x) << endl;
}

class StockPrice
{
public:
    void update(int t, int p)
    {
        if (m_data.find(t) != m_data.end())
            m_sort.erase(m_sort.find(m_data[t]));
        m_data[t] = p;
        m_sort.insert(p);
    }

    int current()
    {
        return m_data.rbegin()->second;
    }

    int maximum()
    {
        return *m_sort.rbegin();
    }

    int minimum()
    {
        return *m_sort.begin();
    }

private:
    map<int, int> m_data;
    multiset<int> m_sort;
};

void test3()
{
    cout << "---------------------" << endl;
    StockPrice s;
    s.update(1, 10);
    s.update(2, 5);
    cout << s.current() << endl;
    cout << s.maximum() << endl;
    s.update(1, 3);
    cout << s.maximum() << endl;
    s.update(4, 2);
    cout << s.minimum() << endl;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
