//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  string ans="";
  int len=0;
  void even(string S,int i,int j,int &len)
  {
      if(S[i]==S[j])
      {while(i>=0 and j<=S.size()-1)
      {
          if(S[i]!=S[j]) break;
          --i;
          ++j;
      }
      if(len<j-i-1)
      {
          len=j-i-1;
          ans=S.substr(i+1,j-i-1);
      }
      }
  }
    string longestPalin (string S) {
        int len=0;
        for(int i=0;i<S.size();i++)
        {
          
                   even(S,i,i,len);
                   even(S,i,i+1,len);
               
           
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends