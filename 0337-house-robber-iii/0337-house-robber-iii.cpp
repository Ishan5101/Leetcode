/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,  unordered_map<TreeNode*, int> &dp) {
        if (root == nullptr)
            return 0;
       // int taken=root->val;
  if (dp.count(root)) return dp[root];
int taken = root->val;
if (root->left)  taken += solve(root->left->left,dp) + solve(root->left->right,dp);
if (root->right) taken += solve(root->right->left,dp) + solve(root->right->right,dp);
        int nottaken = solve(root->left,dp) + solve(root->right,dp);

       return dp[root] = max(taken, nottaken);

    }
    int rob(TreeNode* root) { 
       unordered_map<TreeNode*, int> dp;
        
        return solve(root,dp); }
};