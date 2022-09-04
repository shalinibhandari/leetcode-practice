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
    TreeNode*call(int is,int ie,int in[],int ps,int pe,int pre[],map<int,int>&mp)
    {
        if(is>ie or ps>pe) return NULL;
        TreeNode*n=new TreeNode(pre[ps]);
        int ind=mp[pre[ps]];
        int diff=ind-is;
        n->left=call(is,ind-1,in,ps+1,ps+diff,pre,mp);
        n->right=call(ind+1,ie,in,ps+diff+1,pe,pre,mp);
        return n;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in[inorder.size()];
        int pre[preorder.size()];
        for(int i=0;i<inorder.size();i++)
        { 
            in[i]=inorder[i];
            pre[i]=preorder[i];
            
            
        }
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[in[i]]=i;
        }
        int n=inorder.size()-1;
        return call(0,n,in,0,n,pre,mp);
    }
};