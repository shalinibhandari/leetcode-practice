class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int prev1=nums[0];
        int prev2=max(nums[0],nums[1]);
        for(int i=2;i<nums.size()-1;i++)
        {
            int take=nums[i]+prev1;
            int leave=prev2;
            int p=max(take,leave);
            prev1=prev2;
            prev2=p;
        }
        int ans1=max(prev1,prev2);
         prev1=nums[1];
         prev2=max(nums[1],nums[2]);
         for(int i=3;i<nums.size();i++)
         {
             int take=nums[i]+prev1;
            int leave=prev2;
            int p=max(take,leave);
            prev1=prev2;
            prev2=p;
         }
        int ans2=max(prev1,prev2);
        return max(ans1,ans2);
    }
};