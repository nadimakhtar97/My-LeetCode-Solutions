class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
     
      
      vector<int> res(queries.size(),0);
      int queryNo = 0;
      
      for(vector<int>& query : queries)
      {
        int x = query[0];
        int y = query[1];
        int r = query[2];
        
        for(vector<int> point:points)
        {
          int x1 = point[0];
          int y1 = point[1];
          
          if( (x-x1) * (x-x1) + (y-y1) * (y-y1) <= r*r)
            res[queryNo]++;
        }
        queryNo++;
      }
      
      return res;
        
    }
};