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
    TreeNode* solve(vector<int>&nums)
    {
        if(nums.size()==0)
            return nullptr;
        if(nums.size()==1)
            return new TreeNode(nums[0]);
        int max=INT_MIN;
        int in=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                in=i;
            }
        }
        vector<int>left,right;
        for(int i=0;i<in;i++)
        {
           left.push_back(nums[i]); 
        }
        for(int i=in+1;i<nums.size();i++)
        {
            right.push_back(nums[i]);
            
        }
        TreeNode*root=new TreeNode(nums[in]);
        root->left=solve(left);
        root->right=solve(right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums);
    }
};