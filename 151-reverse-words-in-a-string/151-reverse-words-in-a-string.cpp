class Solution {
public:
    string reverseWords(string s) {
        string a="";
        string s1="";
    
        reverse(s.begin(),s.end());
        int c=0,count=0;
        vector<string>ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(s1.size()>0 )
                {   reverse(s1.begin(),s1.end());
                    ans.push_back(s1);
                    s1="";
                }
                
                    
            }
            else if(s[i]!=' ')
            {
                s1+=s[i];
                
            }
        }
        if(s1.size()>0)
        {
            reverse(s1.begin(),s1.end());
                    ans.push_back(s1);
        }
        for(int i=0;i<ans.size();i++)
        {
            a+=ans[i];
            if(i+1<ans.size())
                a+=' ';
        }
        return a;
    }
};