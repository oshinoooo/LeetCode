#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
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
    int minArray(vector<int>& numbers)
    {
        int ptr1 = 0;
        int ptr2 = numbers.size() - 1;
        while (ptr1 < ptr2)
        {
            int mid = ptr1 + (ptr2 - ptr1) / 2;
            if (numbers[mid] == numbers[ptr2])
                --ptr2;
            else if (numbers[mid] < numbers[ptr2])
                ptr2 = mid;
            else
                ptr1 = mid + 1;
        }
        return numbers[ptr1];
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
    vector<int> numbers = {3, 4, 5, 1, 2};
    cout << s.minArray(numbers) << endl;
    cout << "---------------------" << endl;
    return 0;
}
