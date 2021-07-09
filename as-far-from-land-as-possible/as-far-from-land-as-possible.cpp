class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       
//     MULTI-SOURCE BFS ;
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int distance = 0 ;
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int xx = x + dx[k];
                int yy = y + dy[k];
                
                if(xx<m && xx>=0 && yy<n && yy>=0 && grid[xx][yy]==0)
                {
                    q.push({xx,yy});
                    grid[xx][yy] = grid[x][y] + 1;
                    distance = max(distance,grid[xx][yy]);
                }
            }
        }
        
        
        //  for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        return distance-1;
               
    }
};