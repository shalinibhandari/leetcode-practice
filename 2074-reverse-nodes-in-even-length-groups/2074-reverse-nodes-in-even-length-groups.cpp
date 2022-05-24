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
    void reverse(ListNode*slow,ListNode*fast,ListNode*prev)
    {
        ListNode*next1=fast->next;
        fast->next=NULL;
        ListNode*n=slow,*c,*prev1=NULL;
        while(n)
        {
           c=n->next;
            n->next=prev1;
            prev1=n;
            n=c;
        }
        ListNode*l;
        ListNode*prev2=prev1;
        while(prev2)
        {
    
            l=prev2;
            prev2=prev2->next;
            
        }
      prev->next=prev1;
        l->next=next1;
      
      
       
        
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int i=1,c=0;
        ListNode*slow=head,*fast=head,*prev=head;
        while(fast)
        {
            ++c;
            if(c==i)
            {
                if(i%2==0)
                {   
                    reverse(slow,fast,prev);
                    
                }
                if(i%2==0)
                prev=slow;
                else
                    prev=fast;
                cout<<prev->val;
                if(i%2!=0)
                slow=fast->next;
                else
                {
                    fast=slow;
                    slow=slow->next;
                }
                c=0;
                ++i;
            }
            if(fast->next==NULL)
                break;
            fast=fast->next;
        }
        if(c!=0 and c%2==0)
        {
            reverse(slow,fast,prev);
        }
       
        return head;
    }
};