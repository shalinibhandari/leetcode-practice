class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        vector<int>a;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                a.push_back(matrix[i][j]);
            }
        }
        sort(a.begin(),a.end());
        int c=0;
        for(int i=0;i<a.size();i++)
        {
            ++c;
            if(c==k)
                return a[i];
        }
        return -1;
    }
};