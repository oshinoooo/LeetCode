#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge1(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> out({intervals[0]});

        for (int i = 1; i < intervals.size(); ++i)
        {
            int j;
            for (j = 0; j < out.size(); ++j)
            {
                if (intervals[i][0] <= out[j][0] && out[j][1] <= intervals[i][1])
                {
                    out[j][0] = intervals[i][0];
                    out[j][1] = intervals[i][1];
                    break;
                }
                else if (out[j][0] <= intervals[i][0] && intervals[i][1] <= out[j][1])
                    break;
                else if (intervals[i][0] <= out[j][0] && out[j][0] <= intervals[i][1])
                {
                    out[j][0] = intervals[i][0];
                    break;
                }
                else if (intervals[i][0] <= out[j][1] && out[j][1] < intervals[i][1])
                {
                    out[j][1] = intervals[i][1];
                    break;
                }
            }

            if (j == out.size())
                out.push_back(intervals[i]);
        }
        return out;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> out({intervals[0]});

        for (int i = 1; i < intervals.size(); ++i)
        {
            int j = out.size() - 1;

            if (out[j][1] < intervals[i][0] || intervals[i][1] < out[j][0])
            {
                out.push_back(intervals[i]);
                continue;
            }

            if (intervals[i][0] <= out[j][0] && out[j][0] <= intervals[i][1])
                out[j][0] = intervals[i][0];

            if (intervals[i][0] <= out[j][1] && out[j][1] < intervals[i][1])
                out[j][1] = intervals[i][1];
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> intervals = {{2, 3}, {2, 2}, {3, 3}, {1, 3}, {5, 7}, {2, 2}, {4, 6}};
    vector<vector<int>> out = s.merge(intervals);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
