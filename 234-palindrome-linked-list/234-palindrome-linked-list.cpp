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
class Solution {
public:
    ListNode*reverse(ListNode*head)
    {
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*n;
        while(curr)
        {
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*second=reverse(slow->next);
        ListNode*first=head;
        while(first and second)
        {
            if(first->val!=second->val) return  false;
            first=first->next;
            second=second->next;
        }
        return true;
        
        
    }
};