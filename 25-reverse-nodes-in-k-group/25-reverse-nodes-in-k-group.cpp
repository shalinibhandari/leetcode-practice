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
    
    
    ListNode* reverse(ListNode*head,int k,ListNode*&last)
    {
        
        ListNode*curr=head;
        ListNode*n;
        ListNode*prev=NULL;
        ListNode*pp;
        ListNode*h=head;
        while(k--)
        {
            
            n=curr->next;
            pp=n;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        h->next=pp;
        last=h;
        return prev;
        
        
    }
    int getlength(ListNode*head)
    {
        int c=0;
        while(head)
        {
            ++c;
            head=head->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=getlength(head);
        ListNode*last;
        ListNode*last1;
        ListNode*ans;
        int c=0;
        while(n>=k)
        {
            if(c==0)
            {
                ans=reverse(head,k,last);
                head=last;
                last1=last;
                c=1;
                
            }
            else
            {
                last1->next=reverse(head->next,k,last);
                head=last;
                last1=last;
            }
            n-=k;
        }
        return ans;
    }
};