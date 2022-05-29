// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    void reverse1(struct node*first,struct node*head)
    {
        struct node*prevhead=head->next;
        head->next=NULL;
        struct node*n=first,*c,*prev=NULL;
        while(n)
        {
            c=n->next;
            n->next=prev;
            prev=n;
            n=c;
        }
        first->next=prevhead;
    }
    struct node *reverse (struct node *head, int k)
    { 
        struct node*first=head,*prevfirst,*ans,*prev1;
        int c=0,cc=0;
        while(head)
        {
            ++c;
            if(c==k)
            {
                reverse1(first,head);
                if(cc==0)
                {
                    ++cc;
                    ans=head;
                }
                else
                {
                    prevfirst->next=head;
                }
                c=0;
                prevfirst=first;
                head=first;
                first=first->next;
            }
            prev1=head;
            head=head->next;
        }
         if(c!=0)
         {
             struct node*n=first,*c,*prev=NULL;
             while(n)
             {
                 c=n->next;
                 n->next=prev;
                 prev=n;
                 n=c;
             }
             prevfirst->next=prev;
             
         }
        return ans;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends