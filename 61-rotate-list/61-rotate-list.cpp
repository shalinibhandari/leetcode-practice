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
    int getlength(ListNode*head)
    {
        int c=0;
        while(head)
        {
            head=head->next;
            ++c;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int l=getlength(head);
       if(k==0 or head==NULL or l==1) return head;
        if(k==1 and l==1)  return head;
        
            int k1=k%l;        
        if(k1==0) return head;
    
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*slow=dummy;
        ListNode*fast=dummy;
        while(k1--)
        {
            fast=fast->next;
        }
        
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*ans=slow->next;
        slow->next=NULL;
        fast->next=head;
        head=ans;
        return head;
        
        
    }
};