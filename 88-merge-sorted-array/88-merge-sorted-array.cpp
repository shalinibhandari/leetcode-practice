class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(j<n)
        {  sort(nums2.begin(),nums2.end());
             if(i>=m)
            {
                nums1[i]=nums2[j];
                ++i;
                ++j;
          
              
            }
            
            else if(nums1[i]<nums2[j] or nums1[i]==nums2[j])
            {
                ++i;
            }
            else if(nums2[j]<nums1[i])
            {
                swap(nums1[i],nums2[j]);
                i++;
                
            } 
           
            
        }
        
    }
};