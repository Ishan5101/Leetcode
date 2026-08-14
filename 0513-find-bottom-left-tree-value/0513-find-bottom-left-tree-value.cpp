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
    int leftmost;
    int currdepth;
    void dfs(TreeNode* root, int depth){
        if(!root) return;

        if(currdepth<depth){
            currdepth=depth;
            leftmost=root->val;
        }

        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
        int findBottomLeftValue(TreeNode* root) {
            currdepth=-1;
       dfs(root, 0);

       return leftmost;
    }
};