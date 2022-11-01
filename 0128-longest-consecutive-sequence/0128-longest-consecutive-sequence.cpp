class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int c=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1)==mp.end())
            {
                c=1;
                int n=nums[i];
                while(mp.find(n+1)!=mp.end())
                {
                    ++c;
                    ++n;
                }
            }
            ans=max(ans,c);
        }
        return ans;

        }
};