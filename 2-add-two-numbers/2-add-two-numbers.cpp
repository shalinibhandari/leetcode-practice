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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>a;
        vector<int>b;
        if(l1==NULL and l2!=NULL)  return l2;
        if(l2==NULL and l1!=NULL) return l1;
        while(l1)
        {
            a.push_back(l1->val);
            l1=l1->next;

        }
        while(l2)
        {
            b.push_back(l2->val);
            l2=l2->next;
        }
       reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        ListNode*h;
        int i=a.size()-1,j=b.size()-1;
        int c=0,carry=0;
        ListNode*ans;
        while(i>=0 and j>=0)
        {
            int p=a[i]+b[j]+carry;
            --i;
            --j;
            
            ListNode*n=new ListNode(p%10);
            carry=p/10;
            if(c==0)
            {
                h=n;
                ans=n;
                c=1;
            }
            else
            {
                h->next=n;
                h=n;
            }
        }
        while(i==-1 and j>=0)
        {
            int p=b[j]+carry;
            --j;
            ListNode*n=new ListNode(p%10);
            carry=p/10;
            h->next=n;
            h=n;
        }
        while(j==-1 and i>=0)
        {
            int p=a[i]+carry;
            --i;
            ListNode*n=new ListNode(p%10);
            carry=p/10;
            h->next=n;
            h=n;
        }
        if(carry!=0)
        {
             ListNode*n=new ListNode(carry%10);
            
            h->next=n;
            h=n;
        }
        return  ans;
    }
};