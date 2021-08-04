class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(obstacleGrid,0,0,m,n,dp);
        
    }
    
    int helper(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>>& dp)
    {
        if(i == m-1 && j == n-1 && obstacleGrid[i][j]!=1)
        {
            return 1;
        }
        
        int paths = 0;
        
        if(isSafe(obstacleGrid,i,j,m,n)){
            if(dp[i][j]!=-1)
                return dp[i][j];
                
            return dp[i][j] = helper(obstacleGrid,i+1,j,m,n,dp)+helper(obstacleGrid,i,j+1,m,n,dp);
        }
                
        return 0;

        
    }
    
    bool isSafe(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n)
    {
        if( i>= m || i< 0 || j>=n || j<0 || obstacleGrid[i][j] == -1 || obstacleGrid[i][j] == 1)
            return false;
        
        return true;
        
    }
};