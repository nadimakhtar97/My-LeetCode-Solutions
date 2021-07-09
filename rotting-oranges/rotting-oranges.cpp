class Solution {
public:

    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        int max_distance = 0;
        queue<pair<int,int>> q;
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    distance[i][j] = 0;
                                        
                }
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
                
                if( xx<m && xx>=0 && yy<n && yy>=0 && distance[xx][yy] == INT_MAX && grid[xx][yy] == 1)
                {   
                    q.push({xx,yy});
                    distance[xx][yy] = distance[x][y]+1;
                    max_distance = max(max_distance,distance[xx][yy]);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { 
                if(grid[i][j]==1 && distance[i][j]==INT_MAX)
                    max_distance = -1;
                
                if(distance[i][j]==INT_MAX)
                    cout<<"#"<<" ";
                else
                    cout<<distance[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        return max_distance;
        
    }
};