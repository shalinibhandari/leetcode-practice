//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node*reverse(Node*head)
{
    Node*n=head,*c,*prev=NULL;
    while(n)
    {
        c=n->next;
        n->next=prev;
        prev=n;
        n=c;
    }
    return prev;
}                //3 2 6 5 11 10 15 12                     
class Solution
{
    public:
    Node *compute(Node *head)
    {
        Node*head1=reverse(head);
        //return head1;
        Node*dummy=new Node(0);
        dummy->next=head1;
        while(head1->next)
        {
            if(head1->next->data<head1->data)
            {
                head1->next=head1->next->next;
                //head1->next=head1->next->next;
            }
            else
            {
                head1=head1->next;
            }
        }
        Node*n=dummy->next;
        Node*ans=reverse(n);
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends