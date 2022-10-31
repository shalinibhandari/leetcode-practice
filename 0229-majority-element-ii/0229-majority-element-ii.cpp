class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1;
        int c1=0,c2=0;
        for(auto x:nums)
        {
            
             if(x==num1)
                ++c1;
            else if(x==num2)
                ++c2;
            else if(c1==0)
            {
                num1=x;
                c1=1;
                
            }
            else if(c2==0)
            {
                num2=x;
                c2=1;
            }
           
            else
            {
                --c1;
                --c2;
            }
        }
        int count1=0,count2=0;
        for(auto x:nums)
        {
            if(x==num1)
                ++count1;
            else if(x==num2)
                ++count2;
        }
        vector<int>ans;
        if(count1>nums.size()/3)
             ans.push_back(num1);
        if(count2>nums.size()/3)
            ans.push_back(num2);
        return ans;
        }
};