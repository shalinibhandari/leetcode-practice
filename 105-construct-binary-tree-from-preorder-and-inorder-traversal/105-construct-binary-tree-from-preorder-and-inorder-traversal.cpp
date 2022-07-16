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
    TreeNode*build(int pre[],int prestart,int preend,int in[],int instart,int inend,map<int,int>&mp)
    {
        if(prestart>preend || instart>inend)  return NULL;
        TreeNode*root=new TreeNode(pre[prestart]);
        int ind=mp[root->val];
        int diff=ind-instart;
        
        root->left=build(pre,prestart+1,prestart+diff,in,instart,ind-1,mp);
        root->right=build(pre,prestart+diff+1,preend,in,ind+1,inend,mp);
         return root;    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int n=preorder.size();
        int pre[n],in[n];
        for(int i=0;i<n;i++)
        {
            pre[i]=preorder[i];
            in[i]=inorder[i];
        }
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        TreeNode*root=build(pre,0,n-1,in,0,n-1,mp);
        return root;
    }
    
     
};