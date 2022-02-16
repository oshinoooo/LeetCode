#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDistance(vector<int>& colors)
    {
        int ptr1 = 0;
        int ptr2 = colors.size() - 1;

        while (ptr1 < colors.size() - 1)
        {
            if (colors[ptr1] == colors[colors.size() - 1])
                ++ptr1;
            else
                break;
        }

        if (ptr1 == colors.size() - 1)
            return 0;

        while (0 < ptr2)
        {
            if (colors[0] == colors[ptr2])
                --ptr2;
            else
                break;
        }

        return max(int(colors.size() - 1 - ptr1), ptr2);
    }

    int wateringPlants(vector<int>& plants, int capacity)
    {
        int steps = 0;
        int cur_capacity = capacity;

        for (int i = 0; i < plants.size(); ++i)
        {
            if (plants[i] <= cur_capacity)
            {
                cur_capacity -= plants[i];
                ++steps;
            }
            else
            {
                cur_capacity = capacity - plants[i];
                steps += i * 2 + 1;
            }
        }

        return steps;
    }
};

class RangeFreqQuery
{
public:
    RangeFreqQuery(vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); ++i)
            locations[arr[i]].push_back(i);
    }

    int query(int left, int right, int value)
    {
        vector<int>& v = locations[value];
        int j = upper_bound(begin(v), end(v), right) - begin(v);
        int i = lower_bound(begin(v), end(v), left)  - begin(v);
        return j - i;
    }

private:
    unordered_map<int, vector<int>> locations;
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> colors = {1,1,1,6,1,1,1};
    cout << s.maxDistance(colors) << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> plants = {3,2,4,2,1};
    int capacity = 6;
    cout << s.wateringPlants(plants, capacity) << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery r(arr);
    cout << r.query(1, 2, 4) << endl;
    cout << r.query(0, 11, 33) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
