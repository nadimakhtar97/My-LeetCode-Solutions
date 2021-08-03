class Solution {
public:
    int uniquePaths(int m, int n) {
    
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i==1 || j==1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        
        return dp[m][n];
        
        
    }
    
};