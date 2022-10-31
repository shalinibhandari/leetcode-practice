class Solution {
public:
    int call(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i==m-1 and j==n-1)
        {
            
            return 1;
        }
        if(i>m-1 or j>n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=call(i+1,j,m,n,dp)+call(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int p= call(0,0,m,n,dp);   
        if(n==1 and m==1) return p;
        else return dp[0][0];
    }
};