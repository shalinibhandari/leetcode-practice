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
    TreeNode*call(int is,int ie,vector<int>&inorder,int ps,int pe,vector<int>&postorder,map<int,int>&mp)
    {
        if(is>ie or ps>pe) return NULL;
        TreeNode*root=new TreeNode(postorder[pe]);
            int ind=mp[root->val];
            int diff=ind-is;
        root->left=call(is,ind-1,inorder,ps,ps+diff-1,postorder,mp);
        root->right=call(ind+1,ie,inorder,ps+diff,pe-1,postorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return call(0,n-1,inorder,0,n-1,postorder,mp);
    }
};