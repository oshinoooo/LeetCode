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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int sum = 0;
        int end = -1;
        for (auto& time : timeSeries)
        {
            int tmp_end = time + duration - 1;
            if (end < time)
                sum += duration;
            else
                sum += tmp_end - end;
            end = tmp_end;
        }
        return sum;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> timeSeries = {1, 2};
    int duration = 2;
    cout << s.findPoisonedDuration(timeSeries, duration) << endl;
    cout << "---------------------" << endl;
    return 0;
}
