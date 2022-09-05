class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
              if(color[i]==-1)
              {  queue<int>q;
                  q.push(i);
                  color[i]=0;
                  
                  while(!q.empty())
                  {  
                      auto node=q.front();
                      q.pop();
                      for(auto x:graph[node])
                      {
                          if(color[x]==-1)
                          {
                              color[x]=!color[node];
                              q.push(x);
                          }
                          else if(color[x]==color[node]) return false;
                      }
                  }
              }
        }
        return true;
    }
};