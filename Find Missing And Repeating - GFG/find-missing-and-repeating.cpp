//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       int *ans=new int[2];
       int x=arr[0],y=0;
       for(int i=1;i<n;i++)
       {
           x^=arr[i];
       }
       for(int i=1;i<=n;i++)
       {
           x^=i;
       }
       
       int set=x & ~(x-1);
       x=0,y=0;
       for(int i=0;i<n;i++)
       {
           if(set&arr[i])
             x^=arr[i];
        else
            y^=arr[i];
       }
       for(int i=1;i<=n;i++)
       {
           if(set & i)
             x^=i;
            else
              y^=i;
       }
       //cout<<x<<" "<<y;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==x)
            {
                ans[0]=x;
                ans[1]=y;
                return ans;
            }
            if(arr[i]==y)
            {
                ans[0]=y;
                ans[1]=x;
                return ans;
            }
       }
       ans[0]=y;
       ans[1]=x;
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends