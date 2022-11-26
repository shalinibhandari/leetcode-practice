//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<char,int>mp;
	    for(int i=0;i<str.size();i++)
	    {
	        mp[str[i]]=1;
	    }
	    string ans="";
	    for(int i=0;i<str.size();i++)
	    {
	        if(mp[str[i]]>0)
	         {
	             ans+=str[i];
	             mp[str[i]]=0;
	         }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends