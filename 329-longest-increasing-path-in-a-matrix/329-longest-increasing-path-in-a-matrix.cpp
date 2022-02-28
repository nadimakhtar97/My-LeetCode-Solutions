class Solution {
public:
    
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    int longestPath = 1;
    int m,n;
    vector<vector<int>> cache;
    
    
    int dfs(int row,int col,vector<vector<int>>& matrix){
        
        if(cache[row][col]!=0)
            return cache[row][col];
        
        
        int maxx = 1;
        for(int i=0;i<4;i++){
            
            int x = row + dx[i];
            int y = col + dy[i];
            
            if( x < 0 or x>= m or y < 0 or y >= n or matrix[x][y] <= matrix[row][col])
                continue;
            
            int len = 1 + dfs(x,y,matrix);
            maxx = max(maxx,len);
            
        }
        
        return cache[row][col] = maxx;
        
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        m = rowSize;
        n = colSize;
        cache.resize(m,vector<int>(n,0));
        
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                int len = dfs(i,j,matrix);
                longestPath = max(longestPath,len);
            }
        }
        
        
        return longestPath;
        
    }
};