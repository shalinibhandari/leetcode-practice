class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        if(s.size()==1)  return false;
        int o=0,c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{' or s[i]=='(' or s[i]=='[')
            {  s1.push(s[i]);
              ++o;
            }
            if(s[i]==']' or s[i]=='}' or s[i]==')')
            {
                ++c;
                if(s1.empty()) return false;
                char ch=s1.top();
                if(ch=='[' and s[i]==']')
                    s1.pop();
                else if(ch=='{' and s[i]=='}')
                    s1.pop();
                else if(ch=='(' and s[i]==')')
                    s1.pop();
                else 
                    return false;
            }
        }
        if(c>o) return false;
        if(s1.empty()) return true;
        else  return false;
    }
};