// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>parent;
        queue<Node*>q1;
        Node*res;
        q1.push(root);
        int c=0;
        while(!q1.empty())
        {
            Node*node=q1.front();
            q1.pop();
            if(node->data==target)
            {
                res=node;
            }
            if(node->left)
            {
                parent[node->left]=node;
                q1.push(node->left);
                
            }
            if(node->right)
            {
                parent[node->right]=node;
                q1.push(node->right);
                
            }
            
        }
        
        queue<Node*>q;
        q.push(res);
        int count=0;
        unordered_map<Node*,bool>visited;
        visited[res]=true;
        while(!q.empty())
        {
            int n=q.size();
            ++c;
           
            for(int i=0;i<n;i++)
            {
                Node*n=q.front();
                q.pop();
                if(n->left and !visited[n->left])
                {
                    q.push(n->left);
                    visited[n->left]=true;
                }
                if(n->right and !visited[n->right])
                {
                    q.push(n->right);
                    visited[n->right]=true;
                }
                if(parent[n] and !visited[parent[n]])
                {
                    q.push(parent[n]);
                    visited[parent[n]]=true;
                }
            }
           
        }
        
        return c-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends