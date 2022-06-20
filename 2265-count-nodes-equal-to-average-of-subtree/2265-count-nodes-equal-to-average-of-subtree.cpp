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
    int height(TreeNode*root)
    {
        if(root==NULL)
            return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    void call(int k,vector<TreeNode*>&a,TreeNode*root)
    {
        if(root==NULL)
            return ;
        if(k==1)
        {
            a.push_back(root);
        }
        call(k-1,a,root->left);
        call(k-1,a,root->right);
        return ;
    }
    void call1(TreeNode*root,int &count,int &sum)
    {
        if(root==NULL)
        {
            return ;
            
        }
        sum+=root->val;
        ++count;
        call1(root->left,count,sum);
        call1(root->right,count,sum);
    }
    int averageOfSubtree(TreeNode* root) {
        int h=height(root);
        vector<TreeNode*>a;
        for(int i=1;i<=h;i++)
        {
            call(i,a,root);
        }
        int c=0;
        for(auto x:a)
        {
            int count=0;
            int sum=0;
            call1(x,count,sum);
    
            int p=sum/count;
           
            if(x->val==p)
            {
                ++c;
            }
            
        }
        return c;
    }
};