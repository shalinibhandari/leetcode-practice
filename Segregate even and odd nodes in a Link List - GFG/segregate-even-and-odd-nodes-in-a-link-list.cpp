//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node* divide(int N, Node *head){
        Node*even=new Node(0);
        Node*odd=new Node(0);
        int e=0,o=0;
        Node*ev=NULL,*od=NULL;
        while(head)
        {
            if(head->data%2==0)
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
        if(ev==NULL)
          return od;
        else
           ans=ev;
        if(odd==NULL)
            return ev;
        else
        {even->next=od;
        odd->next=NULL;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends