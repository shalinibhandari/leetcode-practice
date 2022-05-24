/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<TreeNode*> list;
    bool isSubPath(ListNode* head, TreeNode* root) {
        headlist(head,root);
        for(TreeNode *x :list)
        {
            if(check(head,x))
                return true;
        }
        return false;
    }
    void headlist(ListNode*head,TreeNode*root)
    {
        if(root==NULL) return ;
        if(head == NULL) return ;
        if(head->val==root->val)
        {
            list.push_back(root);
        }
        headlist(head,root->left);
        headlist(head,root->right);
    }
    bool check(ListNode*head,TreeNode*root)
    {
        if(head==NULL)
            return true;
        if(root==NULL)
            return false;
        if(head->val==root->val)
        {
            return check(head->next,root->left)||check(head->next,root->right);
        }
        return false;
    }
};