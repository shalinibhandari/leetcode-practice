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
        ListNode*prev=NULL,*n,*c=head;
        while(c)
        {
            n=c->next;
            c->next=prev;
            prev=c;
            c=n;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode*dummy=new ListNode();
        dummy->next=head;
        ListNode*slow=dummy,*fast=dummy;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*right=reverse(slow->next);
        slow->next=NULL;
        
        while(head and right)
        {
            if(head->val!=right->val) return false;
            head=head->next;
            right=right->next;
        }
        return true;
    }
};