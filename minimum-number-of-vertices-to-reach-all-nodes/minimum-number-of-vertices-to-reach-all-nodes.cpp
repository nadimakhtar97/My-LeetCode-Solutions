class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
      vector<bool> incoming(n,false);
      vector<int> res;
      
      for(auto& edge : edges)
      {
        incoming[edge[1]] = true;
      }
      
      for(auto a : incoming) cout<<a<<" ";
      cout<<endl;
      
      for(int i=0;i<n;i++)
      {
        if(!incoming[i])
          res.push_back(i);
      }
      
      return res;
    }
};