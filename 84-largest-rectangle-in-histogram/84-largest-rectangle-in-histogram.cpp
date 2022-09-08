class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ans=0;
        stack<int>s;
        int n=height.size();
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() and (i==n or height[s.top()]>=height[i]))
            {
                int height1=height[s.top()];
                s.pop();
                int width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                ans=max(ans,height1*width);
            }
            s.push(i);
            
        }
        return ans;
    }
};