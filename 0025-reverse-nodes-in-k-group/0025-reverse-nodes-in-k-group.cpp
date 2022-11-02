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
    int length(ListNode*head)
    {
        int c=0;
        while(head)
        {
            ++c;
            head=head->next;
        }
        return c;
    }
    ListNode*reverse(ListNode*head,int k,ListNode*&nextnode)
    {
        ListNode*nn;
        ListNode*p=head;
        ListNode*prev=NULL,*n;
        ListNode*c=head;
        while(k--)
        {
            n=c->next;
            nn=n;
            c->next=prev;
            prev=c;
            c=n;
        }
        p->next=nn;
        nextnode=p;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l=length(head);
        if(k==1) return head;
        if(k>l) return head;
        ListNode*ans=head;
        ListNode*nextnode,*conn;
        int c=0;
        while(l>=k)
        {
            if(c==0)
            {
                ans=reverse(head,k,nextnode);
                head=nextnode;
                conn=nextnode;
                c=1;
            }
            else
            {
                conn->next=reverse(head->next,k,nextnode);
                head=nextnode;
                conn=nextnode;
            }
            l-=k;
        }
        return ans;
    }
};