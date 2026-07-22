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
    void dfs(TreeNode* root, int &count, int rootval) {
        if (root == nullptr) return;

        if (root->val >= rootval)
            count++;

        rootval = max(rootval, root->val);

        dfs(root->left, count, rootval);
        dfs(root->right, count, rootval);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, count, root->val);
        return count;
    }
};