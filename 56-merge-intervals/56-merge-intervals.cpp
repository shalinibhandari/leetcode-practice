class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
        int a=intervals[0][0],b=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {   
            if(intervals[i][0]<a and intervals[i][1]<a)
            {
                 vector<int>a1;
                a1.push_back(a);
                a1.push_back(b);
                ans.push_back(a1);
                a=intervals[i][0];
                b=intervals[i][1];
            }
           else if(intervals[i][0]<=a or (intervals[i][0]>=a and intervals[i][0]<=b) )
           {
               a=min(a,intervals[i][0]);
               b=max(b,intervals[i][1]);
           }
            else
            {
                vector<int>a1;
                a1.push_back(a);
                a1.push_back(b);
                ans.push_back(a1);
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        vector<int>a1;
                a1.push_back(a);
                a1.push_back(b);
                ans.push_back(a1);
        return ans;
        
    }
};