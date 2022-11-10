//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        string ans="";
        int i=0,j=1;
        ans+=s[0];
        string ss;
        while(1)
         {
              
            ans="";
            
            
            int c=0;
           
             for(int i=0;i<s.size();i++)
           {
               if((i>0 and s[i]==s[i-1]) or (i<s.size() and s[i]==s[i+1]))
                  {
                      c=1;
                      continue;
                  }
               else
                  ans+=s[i];
           }
           s=ans;
           //cout<<ans<<" ";
          if(s.size()==0 or c==0) break;
         }
         
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends