class Solution {
public:
    vector<int> minOperations(string boxes) {
      
      vector<int> pos;
      vector<int> res;
      int n = boxes.size();
      
      for(int i=0;i<n;i++)
        if(boxes[i]=='1')
          pos.push_back(i);
    
      countOperations(pos,res,n);
      
      return res; 
    }
  
    void countOperations(vector<int>&pos,vector<int>&res,int n)
    {
      int m = pos.size();
      for(int i=0;i<n;i++)
      {
        int operations = 0;
        for(int j=0;j<m;j++)
        {
          operations += abs(i-pos[j]);
        }
        res.push_back(operations);
      }
    }
      
};