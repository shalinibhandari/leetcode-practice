class Solution {
public:
    void call(int s,int e,string s1,int &l,int &r)
    {
        while(s>=0 and e<=s1.size()-1 and s1[s]==s1[e])
        {
            s--;
            e++;
        }
        if(e-s-1>r)
        {
            l=s+1;
            r=e-s-1;
        }
    }
    string longestPalindrome(string s) {
        int l=0,r=0;
        if(s.size()==1) return s;
        for(int i=0;i<s.size()-1;i++)
        {
            
            call(i,i,s,l,r);
            call(i,i+1,s,l,r);
        }
        return s.substr(l,r);
        
    }
};