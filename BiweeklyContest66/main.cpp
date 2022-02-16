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
    int countWords(vector<string>& words1, vector<string>& words2)
    {
        unordered_map<string, int> m1;
        for (auto& word : words1)
            ++m1[word];

        unordered_map<string, int> m2;
        for (auto& word : words2)
            ++m2[word];

        int count = 0;
        for (auto& it : m1)
        {
            if (it.second == 1 && m2[it.first] == 1)
                ++count;
        }

        return count;
    }

    int minimumBuckets(string street)
    {
        int length = street.size();
        int count = 0;

        for (int i = 0; i < length; ++i)
        {
            if (street[i] == 'H')
            {
                if (0 <= i - 1 && street[i - 1] == 'X')
                    continue;

                if (i + 1 < length && street[i + 1] == '.')
                {
                    street[i + 1] = 'X';
                    ++count;
                }
                else if (0 <= i - 1 && street[i - 1] == '.')
                    ++count;
                else
                    return -1;
            }
        }

        return count;
    }

    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
    {
        int sum = 0;

        if (startPos[0] < homePos[0])
        {
            for (int i = startPos[0] + 1; i <= homePos[0]; ++i)
                sum += rowCosts[i];
        }
        else
        {
            for (int i = homePos[0]; i <= startPos[0] - 1; ++i)
                sum += rowCosts[i];
        }

        if (startPos[1] < homePos[1])
        {
            for (int i = startPos[1] + 1; i <= homePos[1]; ++i)
                sum += colCosts[i];
        }
        else
        {
            for (int i = homePos[1]; i <= startPos[1] - 1; ++i)
                sum += colCosts[i];
        }

        return sum;
    }
};

int test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words1 = {"leetcode","is","amazing","as","is"};
    vector<string> words2 = {"amazing","leetcode","is"};
    cout << s.countWords(words1, words2) << endl;
    return 0;
}

int test2()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.minimumBuckets("") << endl;
    return 0;
}

int test3()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> out;
    vector<int> startPos = {5, 5};
    vector<int> homePos  = {5, 2};
    vector<int> rowCosts = {7,1,3,3,5,3,22,10,23};
    vector<int> colCosts = {5,5,6,2,0,16};
    cout << s.minCost(startPos, homePos, rowCosts, colCosts) << endl;
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
