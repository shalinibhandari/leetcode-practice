class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left;
        vector<int>right(nums.size());
        int l=1,r=1;
        for(int i=0;i<nums.size();i++)
        {
            left.push_back(l);
            right[nums.size()-i-1]=r;
            l*=nums[i];
            r*=nums[nums.size()-1-i];
            
        }
        vector<int>ans;
        for(int i=0;i<left.size();i++)
        {   //cout<<left[i]<<" "<<right[i]<<"\n";
            ans.push_back(left[i]*right[i]);
        }
        return ans;
            
    }
};