/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int c=0,c1=0,aa=0;
    TreeNode*ans=NULL;
    void call(TreeNode*root,TreeNode*p,TreeNode*q,vector<TreeNode*>&a,vector<TreeNode*>&b)
    {
        if(root==NULL) return ;
        if(c==0)  a.push_back(root);
        if(p->val==root->val)  c=1;
        if(c1==0)  b.push_back(root);
        if(q->val==root->val) c1=1;
        call(root->left,p,q,a,b);
        call(root->right,p,q,a,b);
        if(c==0) a.pop_back();
        if(c1==0) b.pop_back();
        

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*>a;
       vector<TreeNode*>b;
       call(root,p,q,a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
         for(auto x:a)
         {
             for(auto y:b)
             {
                 if(x->val==y->val)
                     return x;
             }
         }
        return NULL;
        
    }
};