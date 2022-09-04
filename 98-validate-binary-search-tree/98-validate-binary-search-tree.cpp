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
    long long bound=-1e10;
    bool call(TreeNode*root)
    {
        if(root==NULL) return true;
        bool l=call(root->left);
        if(bound>=root->val) return false;
        bound=root->val;
        bool r=call(root->right);
        return l and r;
    }
    bool isValidBST(TreeNode* root) {
        return call(root);
    }
};