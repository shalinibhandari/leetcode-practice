class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],ans1=nums[0],a=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(ans,ans1);
            ans=max(nums[i],(nums[i]*ans));
            ans1=min(nums[i],(nums[i]*ans1));
            a=max(a,ans);
        }
        return a;
    }
};