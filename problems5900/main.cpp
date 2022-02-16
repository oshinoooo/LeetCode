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
#include <cctype>

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
    vector<int> platesBetweenCandles1(string s, vector<vector<int>>& queries)
    {
        map<int, int> position_count;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*')
                ++count;
            position_count[i] = count;
        }

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

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)
    {
        vector<int> locations;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '|')
                locations.push_back(i);
        }

        vector<int> out;
        for (auto query : queries)
        {
            int l = lower_bound(locations.begin(), locations.end(), query[0]) - locations.begin();
            int r = upper_bound(locations.begin(), locations.end(), query[1]) - locations.begin();
            --r;
            if (locations[l] + 1 < locations[r])
                out.push_back(locations[r] - locations[l] + 1 - (r - l + 1));
            else
                out.push_back(0);
        }
        return out;
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
    string str = "**|**|***|";
    vector<vector<int>> queries = {{2, 5}, {5, 9}};
    vector<int> out = s.platesBetweenCandles(str, queries);
    for (auto num :out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
