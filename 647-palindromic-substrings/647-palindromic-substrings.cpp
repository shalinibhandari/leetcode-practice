class Solution {
public:
    void call(int i,int j,string s,int &ans)
    {
        while(i>=0 and j<=s.size()-1 and s[i]==s[j])
        {  ++ans;
            i--;
            j++;
        }
        
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            call(i,i,s,ans);
            call(i,i+1,s,ans);
        }
        return ans;
    }
};