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
    void call(vector<int>&temp,int k,TreeNode*root)
    {
        if(root==NULL)
            return ;
        if(k==1)
        temp.push_back(root->val);
        call(temp,k-1,root->left);
        call(temp,k-1,root->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int h=height(root);
        for(int i=1;i<=h;i++)
        {
            vector<int>temp;
            call(temp,i,root);
            ans.push_back(temp);
        }
        return ans;
    }
};