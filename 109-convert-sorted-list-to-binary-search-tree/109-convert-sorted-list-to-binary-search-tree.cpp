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
    TreeNode* call(vector<int>ans,int i,int j)
    {   if(i>j)
        return NULL;
        int mid=(i+j)/2;
        TreeNode*root=new TreeNode(ans[mid]);
        root->left=call(ans,i,mid-1);
        root->right=call(ans,mid+1,j);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
     
        vector<int>ans;
        while(head)
        {
            ans.push_back(head->val);
            head=head->next;
        }
       return call(ans,0,ans.size()-1);
        
    }
};