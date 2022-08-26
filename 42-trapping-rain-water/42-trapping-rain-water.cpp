class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int lowleft=0;
        int lowright=0;
        int ans=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=lowleft)
                {
                    lowleft=height[left];
                }
                else
                {
                    ans+=lowleft-height[left];
                }
                ++left;
            }
            else
            {
                if(height[right]>=lowright)
                {
                    lowright=height[right];
                }
                else
                    ans+=lowright-height[right];
                --right;
            }
            
        }
        return ans;
    }
};