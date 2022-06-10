class Solution {
public:
    vector<vector<int>>ans;
    void call(vector<int>&nums,int l,int r)
    {
        if(l==r)
        {
            ans.push_back(nums);
            return ;
        }
        for(int i=l;i<=r;i++)
        {
            swap(nums[l],nums[i]);
            call(nums,l+1,r);
            swap(nums[l],nums[i]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
       call(nums,0,nums.size()-1);
        return ans;
    }
};