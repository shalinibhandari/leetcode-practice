class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0,high=n1;
        while(low<=high)
        {
            int cnt1=(low+high)/2;
            int cnt2=((n1+n2+1)/2)-cnt1;
            int l1=cnt1==0?INT_MIN:nums1[cnt1-1];
            int l2=cnt2==0?INT_MIN:nums2[cnt2-1];
            int r1=cnt1==n1?INT_MAX:nums1[cnt1];
            int r2=cnt2==n2?INT_MAX:nums2[cnt2];
            if(l1<=r2 and l2<=r1)
            {
                if((n1+n2)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            if(l1>r2)
                high=cnt1-1;
            else
                low=cnt1+1;
        }
        return 0.0;
    }
};