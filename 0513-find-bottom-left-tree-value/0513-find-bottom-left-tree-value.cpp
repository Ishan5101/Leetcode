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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            auto first= q.front();
            q.pop();

            leftmost=first->val;

            if(first->right) q.push(first->right);
            if(first->left) q.push(first->left);


        }


        return leftmost;
    }
};