class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int>mp(256,-1);
        int i=0,j=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]]!=-1)
            {
                j=max(j,mp[s[i]]+1);
            }
            mp[s[i]]=i;
            ans=max(ans,i-j+1);
            
        }
        return ans;
    }
};