class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//      MULTI-SOURCE BFS
        
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0){
                    
                    q.push({i,j});
                    visited[i][j] = 1;
                    
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
                
                if(xx<m && xx>=0 && yy<n && yy>=0 && mat[xx][yy]==1 && visited[xx][yy]==0)
                {
                    q.push({xx,yy});
                    visited[xx][yy] = 1;
                    mat[xx][yy] = mat[x][y]+1;
                }
                
            }
        }
        
        
        return mat;
        
        
    }
};