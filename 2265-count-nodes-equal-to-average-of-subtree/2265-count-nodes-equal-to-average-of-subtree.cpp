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
    auto dfs(TreeNode* root,int &ans){
        

        if(root==nullptr) return pair<int,int>{0,0};
        auto left= dfs(root->left,ans);
        
        
        auto right = dfs(root->right,ans);

        int totalsum= root->val+left.first+right.first;
        int count=1+left.second + right.second;

        if (totalsum / count == root->val)
            ans++;

        return pair<int,int>{totalsum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};