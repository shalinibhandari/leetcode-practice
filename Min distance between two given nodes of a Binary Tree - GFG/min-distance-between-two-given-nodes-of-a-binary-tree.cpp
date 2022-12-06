//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int c=0;
    void call(Node*root,int a,vector<Node*>&temp)
    {
        if(root==NULL) return;
        if(root->data==a)
        {
            c=1;
            temp.push_back(root);
        }
        if(c==0)
        {
            temp.push_back(root);
        }
        call(root->left,a,temp);
        call(root->right,a,temp);
        if(c==0) temp.pop_back();
    }
    int call1(Node*root,int a)
    {
        if(root==NULL) return 1e9;
        if(root->data==a) return 0;
        return 1+min(call1(root->left,a),call1(root->right,a));
        
    }
    int findDist(Node* root, int a, int b) {
        vector<Node*>p;
        vector<Node*>q;
        call(root,a,p);
        c=0;
        call(root,b,q);
        map<Node*,int>mp;
        for(auto x:p)
        {
            mp[x]++;
        }
        reverse(q.begin(),q.end());
        Node*ans=NULL;
        for(auto x:q)
        {
           
            if(mp.find(x)!=mp.end())
           {
               ans=x;
               break;
           }
        }
        if(ans==NULL) return -1;
        int l=call1(ans,a);
        int r=call1(ans,b);
        return l+r;
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends