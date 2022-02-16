#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
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
    int maxTwoEvents(vector<vector<int>>& events)
    {
        int n = events.size();
        vector<int> preMax(n);
        int ans = 0;
        int i, s;

        sort(events.begin(), events.end());
        preMax[n - 1] = events[n - 1][2];
        for (i = n - 2; i >= 0; --i)
            preMax[i] = max(preMax[i + 1], events[i][2]);

        for (i = 0; i < n; ++i)
        {
            ans = max(ans, events[i][2]);
            s = upper_bound(events.begin(), events.end(), vector<int>{events[i][1] + 1, 0, 0}) - events.begin();
            if (s < n)
                ans = max(ans, events[i][2] + preMax[s]);
        }

        return ans;
    }

    int maxTwoEvents2(vector<vector<int>>& events)
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
};

int main_backup()
{
    // list
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // tree
    cout << "--------------------" << endl;
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n6 = new TreeNode(6);
//    TreeNode* n7 = new TreeNode(7);
//
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    // show
    cout << "--------------------" << endl;
//    vector<int> out;
//    for (auto num : out)
//        cout << num << " ";
//    cout << endl;

    vector<vector<int>> out;
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }

    cout << "--------------------" << endl;
    return 0;
}

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    cout << s.maxTwoEvents(events) << endl;
    cout << "---------------------" << endl;
    return 0;
}
