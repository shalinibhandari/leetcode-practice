/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*front=head;
        Node*first=head;
        //loop1
        while(first!=NULL)
        {
            front=first->next;
            Node*n=new Node(first->val);
            first->next=n;
            n->next=front;
            first=front;
        }
        first=head;
        //loop2
        while(first)
        {
            if(first->random)
            {
                first->next->random=first->random->next;
            }
            first=first->next->next;
        }
        first=head;
    
        Node*dummy1=new Node(0);
        Node*dummy=dummy1;
        
        while(first)
        {
           front=first->next->next;
            dummy->next=first->next;
            first->next=front;
            dummy=dummy->next;
            first=front;
        }
        return dummy1->next;
        
        
        
    }
};