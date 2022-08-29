class Solution {
public:
    void call(int ind,vector<int>&a,vector<vector<int>>&ans,vector<int>&temp,int &target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=ind;i<a.size();i++)
        {
            if(i>ind and a[i]==a[i-1]) continue;
            
            if(a[i]>target) break;
            
            temp.push_back(a[i]);
            int p=target-a[i];
            call(i+1,a,ans,temp,p);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        call(0,candidates,ans,temp,target);
        return ans;
    }
};