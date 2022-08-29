class Solution {
public:
    void call(int i,vector<int>&candidates,int &target,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return ;
        }
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            int p=(target-candidates[i]);
            call(i,candidates,p,ans,temp);
            temp.pop_back();
        }
        call(i+1,candidates,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        call(0,candidates,target,ans,temp);
        return ans;
    }
};