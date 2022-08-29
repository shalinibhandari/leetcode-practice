class Solution {
public:
    bool palin(string s,int s1,int e)
    {
        while(s1<=e)
        {
            if(s[s1++]!=s[e--]) return false;
        
        }
        return true;
        
    }
    

    void call(int ind,string s,vector<vector<string>>&ans,vector<string>&s1)
    {
        if(ind==s.size())
        {
            ans.push_back(s1);
            return ;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(palin(s,ind,i))
            {
                s1.push_back(s.substr(ind,i-ind+1));
                call(i+1,s,ans,s1);
                s1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>s1;
        call(0,s,ans,s1);
        return ans;
    }
};