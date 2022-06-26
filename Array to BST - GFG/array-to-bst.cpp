// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
vector<int>ans;
void call(vector<int>a,int s,int e)
{
    if(s<=e)
       {int mid=(s+e)/2;
       ans.push_back(a[mid]);
       call(a,s,mid-1);
       call(a,mid+1,e);
       }
    
       
}

    vector<int> sortedArrayToBST(vector<int>& nums) {
        call(nums,0,nums.size()-1);
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends