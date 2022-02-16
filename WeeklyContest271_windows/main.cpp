#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countPoints(string rings)
    {
        vector<unordered_set<char>> rods(10);
        for (int i = 0; i < rings.size(); i += 2)
            rods[rings[i + 1] - '0'].insert(rings[i]);

        int count = 0;
        for (auto rod : rods)
        {
            if (rod.size() == 3)
                ++count;
        }

        return count;
    }

    long long subArrayRanges(vector<int>& nums)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp_min = INT_MAX;
            int tmp_max = INT_MIN;
            for (int j = i; j < nums.size(); ++j)
            {
                tmp_min = min(tmp_min, nums[j]);
                tmp_max = max(tmp_max, nums[j]);
                sum += tmp_max - tmp_min;
            }
        }

        return sum;
    }

    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int ptrA = 0;
        int ptrB = plants.size() - 1;
        int waterA = capacityA;
        int waterB = capacityB;
        int sum = 0;

        while (ptrA <= ptrB)
        {
            if (ptrA == ptrB)
            {
                if (waterB <= waterA)
                {
                    if (plants[ptrA] <= waterA)
                        waterA -= plants[ptrA];
                    else
                    {
                        waterA = capacityA - plants[ptrA];
                        ++sum;
                    }
                }
                else
                {
                    if (plants[ptrB] <= waterB)
                        waterB -= plants[ptrB];
                    else
                    {
                        waterB = capacityB - plants[ptrB];
                        ++sum;
                    }
                }
            }
            else
            {
                if (plants[ptrA] <= waterA)
                    waterA -= plants[ptrA];
                else
                {
                    waterA = capacityA - plants[ptrA];
                    ++sum;
                }

                if (plants[ptrB] <= waterB)
                    waterB -= plants[ptrB];
                else
                {
                    waterB = capacityB - plants[ptrB];
                    ++sum;
                }
            }
            ++ptrA;
            --ptrB;
        }

        return sum;
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)
    {
        map<int, int> m;
        for (auto& fruit : fruits)
            m[fruit[0]] += fruit[1];

        int max_fruits = 0;
        for (int i = 0; i <= k; ++i)
        {
            int tmp_startPos = startPos;
            map<int, int> tmp_m = m;
            int tmp_max_fruits = tmp_m[tmp_startPos];
            tmp_m.erase(tmp_startPos);

            for (int j = 0; j < i; ++j)
            {
                tmp_startPos -= 1;
                tmp_max_fruits += tmp_m[tmp_startPos];
                if (tmp_m.count(tmp_startPos))
                    tmp_m.erase(tmp_startPos);

                if (tmp_startPos < fruits[0][0])
                {
                    tmp_startPos -= i - j - 1;
                    break;
                }
            }

            for (int j = 0; j < k - i; ++j)
            {
                tmp_startPos += 1;
                tmp_max_fruits += tmp_m[tmp_startPos];
                if (tmp_m.count(tmp_startPos))
                    tmp_m.erase(tmp_startPos);

                if (fruits.back()[0] < tmp_startPos)
                    break;
            }

            max_fruits = max(max_fruits, tmp_max_fruits);
        }

        return max_fruits;
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.countPoints("B0R0G0R9R0B0G0") << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.subArrayRanges(nums) << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> plants = {2, 2, 3, 3};
    int capacityA = 5;
    int capacityB = 5;
    cout << s.minimumRefill(plants, capacityA, capacityB) << endl;
    return 0;
}

int test4()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
    int startPos = 5;
    int k = 4;
    cout << s.maxTotalFruits(fruits, startPos, k) << endl;
    return 0;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    cout << "---------------------" << endl;
    return 0;
}
