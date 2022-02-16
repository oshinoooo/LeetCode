#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> levelOrder(TreeNode* root)
    {

    }
};

int main()
{
    cout << "------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    Solution s;
    for (auto out : s.levelOrder(n1))
    {

    }
    cout << "------------------" << endl;
    return 0;
}
