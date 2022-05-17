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
    ListNode* partition(ListNode* head, int x) {
       
        ListNode*n = head,*n1=head;
        vector<int>ans;
        vector<int>a;
        while(n)
        {
            ans.push_back(n->val);
            n=n->next;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]<x)
            {
                a.push_back(ans[i]);
                ans[i]=-101;
            }
        }
        for(int i=0;i<ans.size();i++)
        {   
            if(ans[i]!=-101)
            a.push_back(ans[i]);
        }
        
        for(auto x1:a)
        {
            n1->val=x1;
            n1=n1->next;
        }
        return head;
    }
};