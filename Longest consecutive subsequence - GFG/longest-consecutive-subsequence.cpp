//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int ans=0;
      int c=0;
      unordered_map<int,int>mp;
      for(int i=0;i<N;i++)
      {
          mp[arr[i]]++;
      }
      for(int i=0;i<N;i++)
      {
          if(mp.find(arr[i]-1)==mp.end())
          {
              c=1;
              int n=arr[i];
              while(mp.find(n+1)!=mp.end())
              {
                  ++c;
                  ++n;
              }
          }
          ans=max(ans,c);
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends