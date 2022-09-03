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
    bool ans(TreeNode*root,TreeNode*root1)
    {
        if(root==NULL and root1==NULL) return true;
        if((!root and root1) or (root and !root1)) return false;
        if(root->val!=root1->val) return false;
        return ans(root->left, root1->right) and ans(root->right,root1->left);
    }
    bool isSymmetric(TreeNode* root) {
        return ans(root,root);
    }
};