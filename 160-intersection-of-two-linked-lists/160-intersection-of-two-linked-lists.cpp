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
 ListNode *heada=headA,*headb=headB;
        while(heada!=headb)
        {
            if(heada!=NULL)
                heada=heada->next;
            else
                heada=headA;
            if(headb!=NULL)
                headb=headb->next;
            else
                headb=headB;
        }
        return heada;
    }
};