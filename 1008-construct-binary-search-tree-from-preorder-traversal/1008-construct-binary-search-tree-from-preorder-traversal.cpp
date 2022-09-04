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
    TreeNode*call(int &index,vector<int>&preorder,int bound)
    {
        if(index==preorder.size() or preorder[index]>bound) return NULL;
        TreeNode*root=new TreeNode(preorder[index++]);
        root->left=call(index,preorder,root->val);
        root->right=call(index,preorder,bound);
        return root;
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return call(ind,preorder,INT_MAX);
    }
};