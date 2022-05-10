class Solution {
public:
    string reverseWords(string s) {
        vector<string>s1;
        string ch="";
        for(int  i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {  
                if(ch.size()>0)
                {
                    s1.push_back(ch);
                    ch="";
                }
                
                
            }
            else
            {
                ch+=s[i];
            }
               
        }
        if(ch!=" " and ch.size()>0)
        s1.push_back(ch);
        reverse(s1.begin(),s1.end());
        string ans="";
        int c=s1.size();
        int i=0;
        cout<<s1.size();
        for(auto x:s1)
        {       
            ans+=x;
            if(i+1!=c)
            ans+=' ';
            ++i;
        }
        
        return ans;
    }
};