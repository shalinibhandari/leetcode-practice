class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int top= 0, left= 0, right=matrix[0].size()-1, down=matrix.size()-1;
       int dir=0;
       vector<int>ans;
        
        while(left<= right and top<= down)
        {
            if(dir==0)
            {
                for(int i=left; i<=right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                ++top;
            }
            else if(dir==1)
            {
                for(int i=top; i<=down; i++)
                {
                    ans.push_back(matrix[i][right]);
                    
                }
                --right;
            }
            else if(dir==2)
            {
                for(int i=right; i>=left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                --down;
            }
            else
            {
                for(int i=down; i>=top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};