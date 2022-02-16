#include <iostream>
#include <vector>

using namespace std;

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
    int pathSum(TreeNode* root, int targetSum)
    {

    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(1);
    int targetSum = 1;
    cout << s.pathSum(n1, targetSum) << endl;
    cout << "---------------" << endl;
    return 0;
}
