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
    ListNode* insertionSortList(ListNode* head) {
      vector<int>ans;
        ListNode*n=head;
        while(head)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        ListNode*n1=n;
        for(auto x:ans)
        {
            n->val=x;
            n=n->next;
        }
        return n1;
    }
};