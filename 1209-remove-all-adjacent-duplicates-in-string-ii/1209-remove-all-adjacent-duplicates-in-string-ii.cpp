class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>master;
        stack<char>helper;
      for(auto x:s)
      {
          if(master.empty())
          {
              master.push({x,1});
          }
          else
          {
              auto p=master.top();
              if(p.first!=x)
              {
               master.push({x,1});   
              }
              else
              {
                  master.pop();
                  ++p.second;
                  if(p.second!=k)
                      master.push(p);
                  
                      
              }
          }
      }
        string ans="";
        while(!master.empty())
        {
            auto p=master.top();
            master.pop();
            while(p.second--)
            { 
                ans+=p.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
}; 