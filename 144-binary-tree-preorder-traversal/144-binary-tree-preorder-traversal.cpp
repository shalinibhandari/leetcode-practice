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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root)
        {
            if(root->left==NULL)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            else
            {
                TreeNode*prev=root->left;
                while(prev->right and prev->right!=root)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    ans.push_back(root->val);
                    prev->right=root;
                    root=root->left;
                }
                else
                {
                    prev->right=NULL;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};