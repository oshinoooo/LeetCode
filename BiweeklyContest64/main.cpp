#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        map<string, int> count;
        for (auto str : arr)
            ++count[str];

        int i = 0;
        for (auto str : arr)
        {
            if (count[str] == 1)
                ++i;
            if (i == k)
                return str;
        }
        return "";
    }

    int maxTwoEvents(vector<vector<int>>& events)
    {
        int max_value = 0;
        for (int i = 0; i < events.size(); ++i)
        {
            if (max_value < events[i][2])
                max_value = events[i][2];
            for (int j = i + 1; j < events.size(); ++j)
            {
                if (events[i][1] < events[j][0] || events[j][1] < events[i][0])
                {
                    int tmp = events[i][2] + events[j][2];
                    if (max_value < tmp)
                        max_value = tmp;
                }
            }
        }
        return max_value;
    }

    vector<int> platesBetweenCandles1(string s, vector<vector<int>>& queries)
    {
        vector<int> out;

        for (int i = 0; i < queries.size(); ++i)
        {
            int ptr1 = queries[i][0];
            int ptr2 = queries[i][1];

            while (ptr1 < s.size())
            {
                if (s[ptr1] == '|')
                    break;
                ++ptr1;
            }

            while (0 <= ptr2)
            {
                if (s[ptr2] == '|')
                    break;
                --ptr2;
            }

            int count = 0;
            if (ptr1 + 1 < ptr2)
            {
                for (int j = ptr1 + 1; j < ptr2; ++j)
                {
                    if (s[j] == '*')
                        ++count;
                }
            }
            out.push_back(count);
        }

        return out;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)
    {
        map<int, int> position_count;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*')
                ++count;
            position_count[i] = count;
        }

        for(auto num : position_count)
            cout << num.second << " ";
        cout << endl;

        vector<int> out;
        for (int i = 0; i < queries.size(); ++i)
        {
            int ptr1 = queries[i][0];
            int ptr2 = queries[i][1];

            while (ptr1 < s.size())
            {
                if (s[ptr1] == '|')
                    break;
                ++ptr1;
            }

            while (0 <= ptr2)
            {
                if (s[ptr2] == '|')
                    break;
                --ptr2;
            }

            if (ptr1 + 1 < ptr2)
                out.push_back(position_count[ptr2] - position_count[ptr1]);
            else
                out.push_back(0);
        }

        return out;
    }
};

void test1()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;
    cout << s.kthDistinct(arr, k) << endl;
}

void test2()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    cout << s.maxTwoEvents(events) << endl;
}

void test3()
{
    cout << "---------------------" << endl;
    Solution s;
    string str = "**|**|***|";
    vector<vector<int>> queries = {{2, 5}, {5, 9}};
    vector<int> out = s.platesBetweenCandles(str, queries);
    for (auto num :out)
        cout << num << " ";
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    cout << "---------------------" << endl;
    return 0;
}
