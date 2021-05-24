class Solution {
public:
  
    void dfs(vector<vector<int>>& g,vector<vector<int>>& paths,vector<int>& path, int curr)
    {
      path.push_back(curr);
      if(curr == g.size()-1)
      {
        paths.push_back(path);
      }
      else
      {
          for(auto& adj : g[curr])
          dfs(g,paths,path,adj);
      }
      path.pop_back();
    }
  
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
      
      vector<vector<int>> paths;
      vector<int> path;
      
      dfs(g,paths,path,0);
      
      return paths;
        
    }
};