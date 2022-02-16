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
    vector<int> dailyTemperatures1(vector<int>& temperatures)
    {
        vector<int> out(temperatures.size(), 0);
        stack<int> sta;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()])
            {
                out[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }

        return out;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> sta;
        vector<int> out(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()])
            {
                out[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {73,74,75,71,69,72,76,73};
    vector<int> out = s.dailyTemperatures(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
