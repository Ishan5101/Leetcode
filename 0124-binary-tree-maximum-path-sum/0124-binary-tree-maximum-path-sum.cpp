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
    int maxi;

    int solve(TreeNode* root){
        if(root==nullptr) return 0;
    int l= solve(root->left);
    int r= solve(root->right);

    int dono= l+r+root->val;
    int onebest= max(l,r)+root->val;
    int onerootbest= root->val;

    maxi=max({maxi,dono,onebest,onerootbest});

    return max(onebest,onerootbest);
    }
    int maxPathSum(TreeNode* root) {
        maxi=INT_MIN;
        solve(root);
        return maxi;
    }
};