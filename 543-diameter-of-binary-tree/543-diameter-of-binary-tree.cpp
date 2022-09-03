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
    int call(TreeNode*root,int &maxi)
    {
        if(root==NULL) return 0;
        int ls=call(root->left,maxi);
        int rs=call(root->right,maxi);
        maxi=max(maxi,ls+rs);
        return max(ls,rs)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        call(root,maxi);
        return maxi;
    }
};