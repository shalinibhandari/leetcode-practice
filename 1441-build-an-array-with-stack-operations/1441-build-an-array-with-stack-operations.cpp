class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>s;
        int i=1;
        for(int j=0;j<target.size();j++)
        {
            if(i==target[j])
            {
                s.push_back("Push");
                i++;
            }
            else
            {
                int c=0;
                while(i<=n and i!=target[j])
                {
                    s.push_back("Push");
                    ++c;
                    i++;
                    
                }
                while(c--)
                {
                    s.push_back("Pop");
                }
                if(i==target[j])
                {
                    s.push_back("Push");
                    i++;
                }
                if(i>n) break;
            }
            
        }
        return s;
    }
};