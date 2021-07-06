class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int largestArea = 0;
        
        
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {   
                    int size = dfs(i,j,rows,cols,grid,visited);
                    if(size>largestArea)
                        largestArea = size;
                }
            }
        }
        
        
        
    return largestArea;
       
        
    }
    
    
    int dfs(int row,int col,int rows,int cols,vector<vector<int>>& grid,vector<vector<bool>>& visited){
           
        visited[row][col]=true;
        int componentSize = 1;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        for(int k=0;k<4;k++)
        {
            int nx = col + dx[k];
            int ny = row + dy[k];
            
            if(nx<cols && nx>=0 && ny<rows && ny>=0 && !visited[ny][nx] && grid[ny][nx]==1) {
                int subComponent = dfs(ny,nx,rows,cols,grid,visited);
                componentSize += subComponent;
            }
              
        }
        
        return componentSize;
           
       }
    
    
    
    
};