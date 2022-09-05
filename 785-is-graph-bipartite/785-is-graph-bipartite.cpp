class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&color)
    {   if(color[node]==-1)
        color[node]=0;
        for(auto x:graph[node])
        {
            if(color[x]==-1)
            {
                color[x]=!color[node];
                if(dfs(x,graph,color)) return true;
            }
            else if(color[x]==color[node]) return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
               if(color[i]==-1)
               {   color[i]=0;
                   if(dfs(i,graph,color)) return false;
               }
        
        }
        return true;
    }
};