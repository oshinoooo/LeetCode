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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> nums;
        nums.insert({0, 1});
        return myPathSum(root, targetSum, 0, nums);
    }

private:
    int myPathSum(TreeNode* root, const int& targetSum, int sum, unordered_map<int, int>& nums) {
        if (!root)
            return 0;

        sum += root->val;
        int count = nums[sum - targetSum];

        ++nums[sum];

        count += myPathSum(root->left, targetSum, sum, nums);
        count += myPathSum(root->right, targetSum, sum, nums);

        --nums[sum];
        sum -= root->val;

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(10);
    TreeNode* n2 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(-3);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(1);
    TreeNode* n7 = new TreeNode(11);
    TreeNode* n8 = new TreeNode(3);
    TreeNode* n9 = new TreeNode(-2);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n7;
    n4->left = n8;
    n4->right = n9;
    n5->right = n6;

    Solution s;
    cout << s.pathSum(n1, 8) << endl;
    cout << "---------------------" << endl;
    return 0;
}
