class Solution {
public:

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int perimeter = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                    dfs(i,j,m,n,grid,visited,perimeter);
            }
        }
                
        return perimeter;
    }
    
    void dfs(int i,int j ,int m ,int n, vector<vector<int>>& grid,vector<vector<int>>& visited, int& perimeter)
    {
        visited[i][j] = 1;
        
        
        for(int k=0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
                       
            if( (x<0) || (x>=m) || (y<0) || (y>=n) ){
                perimeter++;
            }
                        
            if(x<m && x>=0 && y<n && y>=0 && grid[x][y]==0)
            {
                perimeter++;
            }
            
            if( x<m && x>=0 && y<n && y>=0 && visited[x][y]==0 && grid[x][y]==1)
                dfs(x,y,m,n,grid,visited,perimeter);
        }
        
        
        
    }
};