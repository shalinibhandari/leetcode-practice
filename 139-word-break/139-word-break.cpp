class Solution {
public:
    unordered_map<string,int>dp;
    int solve(string s,vector<string>&word)
    {
        if(s.size()==0) return 1;
        if(dp[s]!=0) return dp[s];
        for(int i=1;i<=s.size();i++)
        {
            int f=0;
            string s1=s.substr(0,i);
            for(int j=0;j<word.size();j++)
            {
                if(s1.compare(word[j])==0)
                {
                    f=1;
                    break;
                }
            }
            if(f==1 and solve(s.substr(i,s.size()-i),word)==1) return dp[s]=1;
        }
        return dp[s]=-1;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int p=  solve(s,wordDict);
        if(p==1) return 1;
        else return 0;
        
    }
};