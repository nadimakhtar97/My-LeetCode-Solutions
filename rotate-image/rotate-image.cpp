class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int i = 0;
        
        for(auto row : matrix)
        {
          for(int j=0;j<n;j++)
            {
               matrix[i][j] = row[n-j-1];
              // cout<<row[n-j-1]<<" ";
            }
            i++;
        }
        
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0 ;j<n-i-1;j++)
            {
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        
        
        // for(int i =0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        
    }
};