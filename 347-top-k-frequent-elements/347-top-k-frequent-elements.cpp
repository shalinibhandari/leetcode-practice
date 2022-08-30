class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
        }
        vector<pair<int,int>>temp;
        for(auto x:mp)
        {
            temp.push_back({x.second,x.first});
        }
        sort(temp.begin(),temp.end(),comp);
        vector<int>ans;
        int c=0;
       for(int i=0;i<k;i++)
       {
           ans.push_back(temp[i].second);
       }
        return ans;
    }
};