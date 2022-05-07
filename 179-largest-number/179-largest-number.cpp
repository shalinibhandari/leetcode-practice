class Solution {
public:
    static bool comp(string &a,string &b)
    {
        string a1=a+b;
        string a2=b+a;
        return a1>a2;
        
    }
    string largestNumber(vector<int>& nums) {
    vector<string>s;
        if(nums.size()==1)
            return to_string(nums[0]);
        for(int i=0;i<nums.size();i++)
        {
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(),s.end(),comp);
        string ans="";
       int c=0;
       for(auto x:s)
       {
           ans+=x;
           if(x!="0")
               c=1;
       }
        if(c==1)
        return ans;
        else
            return "0";
    }
};