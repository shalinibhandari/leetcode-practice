/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=getlength(headA);
        int l2=getlength(headB);
        if(l1>l2)
        {
            int p=l1-l2;
            while(p--)
            {
                headA=headA->next;
            }
            while(headA and headB)
            {
                if(headA==headB)  return headA;
                headA=headA->next;
                headB=headB->next;
            }
            return NULL;
        }
        else if(l2>l1)
        {
         
            int p=l2-l1;
            while(p--)
            {
                headB=headB->next;
            }
            while(headA and headB)
            {
                if(headA==headB)  return headA;
                headA=headA->next;
                headB=headB->next;
            }
            return NULL;
        }
        
            while(headA and headB)
            {
                if(headA==headB)  return headA;
                headA=headA->next;
                headB=headB->next;
            }
            return NULL;
        
        
    }
};