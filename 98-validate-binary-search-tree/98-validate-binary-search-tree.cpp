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
        
long long prev=-1e10;
bool isValidBST(TreeNode* root) {
    
    if(root==NULL)
        return true;
    int x=isValidBST(root->left);
    if(prev>=root->val)
    {  
        return false;
    }
     prev=root->val;
    
    int y=isValidBST(root->right);
    return x and y;
    }
};