class Solution {
public:
    int call(int m,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i==m-1 and j==n-1)  return 1;
        if(i>=m or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=call(m,n,i+1,j,dp)+call(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int p=call(m,n,0,0,dp);
        if(n==1 and m==1)  return p;
        else return dp[0][0];
    }
};