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

using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence1(int target)
    {
        vector<vector<int>> out;
        vector<int> tmp;

        int cur = 1;
        int sum = 0;

        while (cur <= target / 2 + 2)
        {
            if (sum == target)
            {
                out.push_back(tmp);
                sum -= tmp.front();
                tmp.erase(tmp.begin());
            }
            else if (sum < target)
            {
                sum += cur;
                tmp.push_back(cur);
                ++cur;
            }
            else
            {
                sum -= tmp.front();
                tmp.erase(tmp.begin());
            }
        }

        return out;
    }

    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> out;

        int cur = 1;
        int sum = 0;

        while (cur <= target / 2 + 2)
        {
            if (sum == target)
            {
                out.push_back(tmp);
                sum -= tmp.front();
                tmp.erase(tmp.begin());
            }
            else if (sum < target)
            {
                sum += cur;
                tmp.push_back(cur);
                ++cur;
            }
            else
            {
                sum -= tmp.front();
                tmp.erase(tmp.begin());
            }
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> out = s.findContinuousSequence(11);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
