class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int maxi=0;
        int i=0,j=0;
        while(i<s.size())
        {
            if(mp[s[i]]!=-1)
            {
                j=max(mp[s[i]]+1,j);
            }
            mp[s[i]]=i;
            maxi=max(maxi,i-j+1);
            ++i;
        }
        return maxi;
    }
};