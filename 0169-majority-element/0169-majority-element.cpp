class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int ans=0;
        for(auto x:nums)
        {
            if(c==0)
                ans=x;
            if(x==ans) ++c;
            else --c;
        }
        return ans;
    }
};