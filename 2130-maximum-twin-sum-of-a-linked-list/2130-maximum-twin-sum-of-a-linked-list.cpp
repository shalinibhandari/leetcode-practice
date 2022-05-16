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
    ListNode*reverse(ListNode*head,ListNode*slow)
    {
        if(head==NULL)
            return head;
        ListNode*c=head,*prev=NULL,*n;
        while(c!=slow)
        {
            n=c->next;
            c->next=prev;
            prev=c;
            c=n;
        }
        head=prev;
        return head;
    }
    int pairSum(ListNode* head) {
       // O(n) and sc O(n)
       /* vector<int>a;
        
        int maxsum=0;
        
        while(head)
        {
            a.push_back(head->val);
            head=head->next;
        
        }
        
        for(int i = 0; i<a.size()/2; i++)
        {
            maxsum = max(maxsum,a[i]+a[a.size()-1-i]);
        }
        
        return maxsum;
        */
        // tc o(n) and sc O(1)
        ListNode*slow=head;
        ListNode*fast=head;
        while(slow and fast)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        head=reverse(head,slow);
        int maxsum=0;
        while(head and slow)
        {
            maxsum=max(maxsum,head->val+slow->val);
            head=head->next;
            slow=slow->next;
        }
        return maxsum;
    }
};