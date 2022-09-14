class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=s.size()-1;
        string temp="",ans="";
        while(i<=j)
        {
            if(s[i]!=' ')
                temp+=s[i];
            else
            {
                if(temp!="")
                {if(ans!="")
                    ans=temp+' '+ans;
                else
                    ans=temp;
                temp="";
                }
            }
            i++;
        }
        if(temp!="")
        {
            if(ans!="")
           {
               ans=temp+' '+ans;
            
           }
            else
                ans=temp;
        }
        return ans;
            
    }
};