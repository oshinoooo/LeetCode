#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST1(TreeNode* root) {
        if (!root)
            return true;
        return myIsValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

    bool isValidBST(TreeNode* root) {
        vector<long long> nums = {LONG_LONG_MIN};
        return myIsValidBST(root, nums);
    }

private:
    bool myIsValidBST(TreeNode* root, long long minValue, long long maxValue) {
        bool out = true;

        if (root->left) {
            if (root->left->val <= minValue || root->val <= root->left->val)
                return false;
            out = myIsValidBST(root->left, minValue, root->val);
        }

        if (!out)
            return out;

        if (root->right) {
            if (maxValue <= root->right->val || root->right->val <= root->val)
                return false;
            out = myIsValidBST(root->right, root->val, maxValue);
        }

        return out;
    }

    bool myIsValidBST(TreeNode* root, vector<long long>& nums) {
        if (!root)
            return true;

        if (!myIsValidBST(root->left, nums))
            return false;

        if (root->val <= nums.back())
            return false;
        nums.push_back(root->val);

        return myIsValidBST(root->right, nums);
    }
};

int main() {
    cout << "-------------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    cout << s.isValidBST(n1) << endl;
    cout << "-------------------" << endl;
    return 0;
}
