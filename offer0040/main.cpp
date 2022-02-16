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
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        if (k == 0)
            return {};

        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < arr.size(); ++i)
            que.push(arr[i]);

        vector<int> out;
        for (int i = 0; i < k; ++i)
        {
            out.push_back(que.top());
            que.pop();
        }
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0,1,2,1};
    vector<int> out = s.getLeastNumbers(nums, 1);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
