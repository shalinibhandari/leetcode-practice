class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<int>s;
        int n=nums.size();
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() and nums[i%n]>=s.top())
            {
                s.pop();
            }
            if(s.empty()) ans[i%n]=-1;
            else ans[i%n]=s.top();
            s.push(nums[i%n]);
        }
        return ans;
        
    }
};