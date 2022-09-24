class Solution {
public:
   
            
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            { 
                if(grid[i][j]!=0) ++count;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int ans=0,c=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        while(!q.empty())
        {
            int k=q.size();
            c+=k;
            while(k--)
            { 
                auto p=q.front();
             q.pop();
            int i=p.first;
            int j=p.second;
          
                visited[i][j]=1;
            if(i+1<=n-1 and grid[i+1][j]==1 and visited[i+1][j]==0) 
            { 
                grid[i+1][j]=2;
                
                q.push({i+1,j});
            }
            if(i-1>=0 and grid[i-1][j]==1 and visited[i-1][j]==0)
            {
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(j+1<=m-1 and grid[i][j+1]==1 and visited[i][j+1]==0)
            {
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            if(j-1>=0 and grid[i][j-1]==1 and visited[i][j-1]==0)
            {
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            }
            if(!q.empty()) ans++;
            
        }
        return count==c?ans:-1;
    }
};