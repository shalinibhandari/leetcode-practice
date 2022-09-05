class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&dfsvisited)
    {
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                if(dfs(x,adj,visited,dfsvisited)) return true;
            }
            else if(visited[x]==1 and visited[x]==dfsvisited[x]) return true;
        }
        dfsvisited[node]=0;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& arr) {
        
        vector<int> adj[V];
        for(int i=0; i<arr.size(); i++){
            int u = arr[i][0];
            int v = arr[i][1];
            adj[v].push_back(u);
        }

        vector<int>visited(V,0);
        vector<int>dfsvisited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,dfsvisited)) return false;
            }
        }
        return true;
    }
};