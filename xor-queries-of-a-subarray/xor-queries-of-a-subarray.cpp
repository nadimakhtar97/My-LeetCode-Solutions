class Solution {
public:
    
    /*
    
      Explanation
      In-place calculate the prefix XOR of input A.

      For each query [i, j],
      if i == 0, query result = A[j]
      if i != 0, query result = A[i - 1] ^ A[j]
    
    */
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      
      int n = arr.size();
      vector<int> preXor(n+1,0);
      vector<int> res;
      
      for(int i=0;i<n;i++)
      {
        preXor[i+1]=arr[i]^preXor[i];
      }
      
      for(auto q : queries)
      {
        if(q[0]==0) res.push_back(preXor[q[1]+1]);
        else
          res.push_back(preXor[q[1]+1] ^ preXor[q[0]] );
      }
      
      
      return res;
      
    
        
    }
};