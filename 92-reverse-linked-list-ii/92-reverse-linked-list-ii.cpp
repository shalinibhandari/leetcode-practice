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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        ListNode* leftpointer=NULL, *rightpointer=NULL, *node=head ,*rightnext,*leftprev=NULL;
        int c1=0;
        int count=0;
        while(node)
        {  
            ++count;
            if(count == left)
            {    ++c1;
                 
                leftpointer=node;
            }
            else if(count == right)
            {
                rightpointer=node;
                
            }
            if(c1==0)
                leftprev=node;
            node=node->next;

        }
    
        if(leftpointer==NULL or rightpointer==NULL)
            return head;
         rightnext=rightpointer->next;
         rightpointer->next=NULL;
        
        ListNode*n=leftpointer,*c,*prev=NULL;
        ListNode*n1=n;
        while(n)
        {
            c=n->next;
            n->next=prev;
            prev=n;
            n=c;
        }
        n1=prev;
        if(leftprev!=NULL)
        {
            leftprev->next=n1;
            leftpointer->next=rightnext;
        }
        else
        {
              head=n1;
              leftpointer->next=rightnext;
            
        }
        return head;
        
           
    }
};