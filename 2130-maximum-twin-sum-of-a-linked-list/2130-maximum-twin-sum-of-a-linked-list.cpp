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
    int pairSum(ListNode* head) {
        vector<int>a;
        
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
        
    }
};