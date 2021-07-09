class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        
//         MULTI-SOURCE BFS
        
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int,int>> q;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                {
                    isWater[i][j]=0;
                    q.push({i,j});                    
                }
                else{
                    isWater[i][j] = INT_MAX;
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
                
                if(xx<m && xx>=0 && yy<n && yy>=0 && isWater[xx][yy]==INT_MAX)
                {
                    q.push({xx,yy});
                    isWater[xx][yy] = isWater[x][y] + 1;
                }
            }
        }
        
        
        return isWater;
        
    }
};