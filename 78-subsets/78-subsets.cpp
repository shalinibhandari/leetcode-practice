class Solution {
public:
    vector<vector<int>>ans;
    void call(int i,vector<int>&nums,vector<int>&temp)
    {  
      ans.push_back(temp);
       for(int j=i;j<nums.size();j++)
       {
            temp.push_back(nums[j]);
          
            call(j+1,nums,temp);
            temp.pop_back();
       }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        call(0,nums,temp);
        
        return ans;
    }
};