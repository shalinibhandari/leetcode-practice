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
    void reorderList(ListNode* head) {
        vector<int>ans;
         
        ListNode* n = head, *n1=head;
        
        while(n)
        {
            ans.push_back(n->val);
            n=n->next;
        }
        
        int i = 0, j = ans.size()-1;
        while(i < j)
        {
             n1->val = ans[i];
             ++i;
             n1 = n1->next;
             n1->val = ans[j];
             --j;
             n1 = n1->next;
        }
        if(ans.size()&1)
        {
            n1->val=ans[i];
            n1=n1->next;
        }
        
        
    }
};