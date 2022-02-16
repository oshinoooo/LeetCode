#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int left  = newInterval[0];
        int right = newInterval[1];

        bool found = false;
        vector<vector<int>> ans;

        for (const auto& interval: intervals)
        {
            if (interval[0] > right)
            {
                if (!found)
                {
                    ans.push_back({left, right});
                    found = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left)
                ans.push_back(interval);
            else
            {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        if (!found)
            ans.push_back({left, right});

        return ans;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> out = s.insert(intervals, newInterval);
    for (auto ou : out)
        cout << "[" << ou[0] << ", " << ou[1] << "] ";
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
