class Solution {
public:
    void call(int col,vector<string>&b,vector<vector<string>>&ans,int n,vector<int>&row,vector<int>&upperdiagonal,vector<int>&lowerdiagonal)
    {
        if(col==n)
        {
            ans.push_back(b);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(!row[i] and !upperdiagonal[i+col] and !lowerdiagonal[n-1+col-i]) {
                row[i]=1;
                upperdiagonal[i+col]=1;
                lowerdiagonal[n-1+col-i]=1;
                b[i][col]='Q';
                call(col+1,b,ans,n,row,upperdiagonal,lowerdiagonal);
                row[i]=0;
                upperdiagonal[i+col]=0;
                lowerdiagonal[n-1+col-i]=0;
                b[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>b(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            b[i]=s;
        }
        vector<int> row(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        call(0,b,ans,n,row,upperdiagonal,lowerdiagonal);
        return ans;
    }
};