class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int t=target-nums[i];
            if(mp.find(t)!=mp.end())
            {
                ans.push_back(mp[t]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};