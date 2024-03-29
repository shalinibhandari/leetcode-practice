//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
      
         
         sort(intervals.begin(),intervals.end());
            int s=intervals[0][0];
         int e=intervals[0][1];
  
         for(int i=0;i<intervals.size();i++)
         {
             int start=intervals[i][0];
             int end=intervals[i][1];
             if(start>=s and start<=e)
             {
                 if(e<=end)
                   e=end;
                  
             }
             else
             {
                 vector<int>temp;
                 temp.push_back(s);
                 temp.push_back(e);
                 ans.push_back(temp);
                 s=start;
                 
                 e=end;
             }
         }
         vector<int>temp;
                 temp.push_back(s);
                 temp.push_back(e);
                 ans.push_back(temp);
             
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends