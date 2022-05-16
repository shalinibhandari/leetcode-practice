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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* n1 = new ListNode(0);
        n1->next=head;
        ListNode*slow = n1;
        ListNode*fast = n1;
        
        for(int i = 0; i < n; i++)
        {
            slow=slow->next;
        }
        
        while(slow->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
       
      fast->next=fast->next->next;        
        return n1->next;
    }
};