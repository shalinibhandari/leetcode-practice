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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL) return NULL;
        if(headB==NULL) return NULL;
        ListNode*heada=headA,*headb=headB;
        while(headA or headB)
        {  
        
            if(headA==NULL and headB!=NULL) 
                headA=heada;
            if(headB==NULL and headA!=NULL)
                headB=headb;
            if(headA and headB and headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        
            
        }
        return NULL;
    }
};