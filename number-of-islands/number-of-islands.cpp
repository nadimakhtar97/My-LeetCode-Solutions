class Solution {
    public:

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    int numIslands(vector < vector < char >> & grid) {

        int total_count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    total_count++;
                    flood_fill(i, j, m, n, grid);
                }
        }

    
    return total_count;
}

void flood_fill(int row, int col, int m, int n, vector < vector < char >> & grid) {

    grid[row][col] = '0';

    for (int i = 0; i < 4; i++) {
        int y = row + dy[i];
        int x = col + dx[i];

        if (y < m && y >= 0 && x < n && x >= 0 && grid[y][x] == '1')
            flood_fill(y, x, m, n, grid);
    }

}
};