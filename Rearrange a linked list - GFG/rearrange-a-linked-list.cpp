//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
        Node*even=new Node(0);
        Node*odd=new Node(0);
        int e=0,o=0;
        Node*ev=NULL,*od=NULL;
        int c=0;
        while(head)
        {
            ++c;
            if(c%2==0)
            {
                if(e==0)
                {
                  
                     even->next=head;
                     ev=even->next;
                     ++e;
                }
                else
                   even->next=head;
                   even=even->next;
            }
            else
            {
                if(o==0)
                       {
                           
                           
                           odd->next=head;
                           od=odd->next;
                           ++o;
                       }
                       else
                odd->next=head;
                odd=odd->next;
            }
            head=head->next;
        }
        Node*ans;
        if(od==NULL)
        {
            head=ev;
            return;
        }
        else
        {
            ans=od;
            
        }
        if(ev==NULL)
        {
            head=od;
            return ;
        }
        else
        {  
            
            odd->next=ev;
            even->next=NULL;
        }
        head=ans;
        return ;
        
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends