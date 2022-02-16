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
    bool reorderedPowerOf2(int n)
    {
        vector<int> nums;
        while (n > 0)
        {
            nums.push_back(n % 10);
            n /= 10;
        }

        vector<int> tmp_out;
        vector<vector<int>> outs;
        per(nums, tmp_out, outs);

        for (auto out : outs)
        {
            int tmp = 0;
            for (auto num : out)
            {
                if (num == 0 && tmp == 0)
                    break;
                tmp = tmp * 10 + num;
            }

            if (0 < tmp)
            {
                if (check(tmp))
                    return true;
            }
        }

        return false;
    }

private:
    void per(vector<int>& nums, vector<int>& tmp_out, vector<vector<int>>& outs)
    {
        if (nums.empty())
        {
            outs.push_back(tmp_out);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            tmp_out.push_back(nums[i]);
            vector<int> tmp_nums;
            tmp_nums.insert(tmp_nums.begin(), nums.begin(), nums.begin() + i);
            tmp_nums.insert(tmp_nums.end(), nums.begin() + i + 1, nums.end());
            per(tmp_nums, tmp_out, outs);
            tmp_out.pop_back();
        }
    }

    bool check(int num)
    {
        while (num > 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else
                return false;
        }
        return true;
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
    int input;
    while (cin >> input)
        cout << s.reorderedPowerOf2(input) << endl;
    cout << "---------------------" << endl;
    return 0;
}
