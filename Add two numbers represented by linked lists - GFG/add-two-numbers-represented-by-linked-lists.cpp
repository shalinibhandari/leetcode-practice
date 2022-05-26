// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node*first)
    {
         Node*n=first,*c,*prev=NULL;
         while(n)
         {
             c=n->next;
             n->next=prev;
             prev=n;
             n=c;
         }
         return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       
      
        first=reverse(first);
        second=reverse(second);
        Node*head=NULL;
        int carry=0;
        while(first and second)
        {
            int c=first->data+second->data+carry;
            carry=c/10;
            int p=c%10;
            Node*n=new Node(p);
            n->next=head;
            head=n;
            first=first->next;
            second=second->next;
        }
        while(first==NULL and second)
        {
            int c=second->data+carry;
            carry=c/10;
            int p=c%10;
            Node*n=new Node(p);
            n->next=head;
            head=n;
            second=second->next;
        }
            while(second==NULL and first)
        {
            int c=first->data+carry;
            carry=c/10;
            int p=c%10;
            Node*n=new Node(p);
            n->next=head;
            head=n;
            first=first->next;
        }
        if(carry!=0)
        {
            Node*n=new Node(carry);
            n->next=head;
            head=n;
            
        }
        return head;
        
        
 
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends