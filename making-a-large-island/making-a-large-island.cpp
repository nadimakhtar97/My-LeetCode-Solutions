class Solution {
  public:

    int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,-1,1};

  int largestIsland(vector < vector < int >> & grid) {

    int color = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector < vector < int >> visited(m, vector < int > (n, 0));
    map < int, int > color_count;
    int largestIsland = 0;

    color_count[0] = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 and visited[i][j] == 0) {
          int total_nodes = 0;
          color++;
          total_nodes = flood_fill(i, j, m, n, grid, visited, color, total_nodes);
          color_count[color] = total_nodes;
        }
      }
    }

    for (auto m: color_count) {
      largestIsland = max(largestIsland, m.second);
    }

    for (int i = 0; i < m; i++) {

      for (int j = 0; j < n; j++) {

        if (grid[i][j] == 0) {

          set < int > nbrIsland;
          for (int k = 0; k < 4; k++) {

            int ii = i + dx[k];
            int jj = j + dy[k];
            if (ii < m && ii >= 0 && jj < n && jj >= 0)
              nbrIsland.insert(grid[ii][jj]);

          }

          int ans = 1;
          for (auto s: nbrIsland)
            ans += color_count[s];

          largestIsland = max(largestIsland, ans);
        }

      }
    }

    return largestIsland;
  }

  int flood_fill(int i, int j, int m, int n, vector < vector < int >> & grid, vector < vector < int >> & visited, int color, int total_nodes) {
    visited[i][j] = 1;
    grid[i][j] = color;
    total_nodes++;

    for (int k = 0; k < 4; k++) {
      int ii = i + dx[k];
      int jj = j + dy[k];
      if (ii < m && ii >= 0 && jj < n && jj >= 0 && grid[ii][jj] == 1 && visited[ii][jj] == 0)
        total_nodes = flood_fill(ii, jj, m, n, grid, visited, color, total_nodes);
    }

    return total_nodes;
  }

};