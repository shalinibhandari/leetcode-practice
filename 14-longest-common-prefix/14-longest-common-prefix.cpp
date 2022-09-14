class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        string s=strs[0];
        
        for(int i=0;i<s.size();i++)
        {   
            int c=0;
            for(int j=1;j<strs.size();j++)
            {
                string s1=strs[j];
                if(s1[i]!=s[i])  
                {
                    c=1;
                    break;
                }
            }
            if(c==0)
                ans+=s[i];
            else
                break;
        }
        return ans;
    }
};