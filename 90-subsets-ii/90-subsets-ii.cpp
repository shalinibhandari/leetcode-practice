class Solution {
public:
    void subset(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp)
    {
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind and nums[i]==nums[i-1])  continue;
            temp.push_back(nums[i]);
            subset(i+1,nums,ans,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        subset(0,nums,ans,temp);
        return ans;
        
    }
};