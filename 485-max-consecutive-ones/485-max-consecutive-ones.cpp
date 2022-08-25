class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=1;
        int ans=0;
        if(nums.size()==1 and nums[0]==1) return 1;
        for(int i=0;i<nums.size()-1;i++)
        {    
            if(nums[i]==1 and nums[i]==nums[i+1])
            {
                ++c;
                ans=max(ans,c);
            }
            else if(nums[i]==1)
                ans=max(ans,1);
            else
                c=1;
        }
        if(nums[nums.size()-1])
            ans=max(ans,1);
        return ans;
    }
};