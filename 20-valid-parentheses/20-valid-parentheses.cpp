class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        if(s.size()==1) return false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='}' or s[i]==']' or s[i]==')')
            {
                if(s1.empty()) return false;
            
            
        
                if(s[i]==']' and s1.top()=='[')
                    s1.pop();
                else if(s[i]=='}' and s1.top()=='{')
                    s1.pop();
                else if(s[i]==')' and s1.top()=='(')
                    s1.pop();
                else return false;
        
            }
            else s1.push(s[i]);
        }
        return s1.empty();
    }
};