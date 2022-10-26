class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix[i].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       int j=0;
        while(j<matrix[0].size()/2)
        {
            for(int i=0;i<matrix.size();i++)
            {
                swap(matrix[i][j],matrix[i][matrix.size()-1-j]);
            }
                ++j;
        }
        
        
    }
};