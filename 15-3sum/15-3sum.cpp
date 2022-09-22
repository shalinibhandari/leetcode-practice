class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 or (i>0 and nums[i]!=nums[i-1]))
            {
                int s=i+1;
                int e=nums.size()-1;
                int sum=0-nums[i];
                while(s<e)
                {
                    if(nums[s]+nums[e]==sum)
                    {
                        vector<int>t;
                        t.push_back(nums[i]);
                        t.push_back(nums[s]);
                        t.push_back(nums[e]);
                        ans.push_back(t);
                        while(s<e and nums[s]==nums[s+1])s++;
                        while(s<e and nums[e]==nums[e-1])e--;
                        s++;
                        e--;
                    }
                    else if(nums[s]+nums[e]<sum)
                        s++;
                    else
                        e--;
                }
            }
        }
        return ans;   
    }
};