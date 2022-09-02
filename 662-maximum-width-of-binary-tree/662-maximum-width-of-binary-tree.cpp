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
    int widthOfBinaryTree(TreeNode* root) {
     
        if(!root)  return 0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int min=q.front().second;
            int n=q.size();
            int f,l;
            for(int i=0;i<n;i++)
            {
                TreeNode*node=q.front().first;
                long long  k=q.front().second-min;
                q.pop();
                if(i==0) f=k;
                if(i==n-1) l=k;
                if(node->left)
                {
                    q.push({node->left,2*k+1});
                }
                if(node->right)
                {
                    q.push({node->right,2*k+2});
                }
            }
            int p=l-f+1;
            ans=max(ans,p);
        }
        return ans;
    }
};