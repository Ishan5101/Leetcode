/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total = 0;

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        findpath(root, 0LL, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return total;
    }

    void findpath(TreeNode* root, long long sum, long long target) {
        if (root == nullptr) return;

        sum += root->val;

        if (sum == target)
            total++;

        findpath(root->left, sum, target);
        findpath(root->right, sum, target);
    }
};