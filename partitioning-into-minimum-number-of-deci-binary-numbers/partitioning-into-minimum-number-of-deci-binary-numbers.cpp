class Solution {
public:
    int minPartitions(string n) {
      
      char mx = '0';
      int count  = 0;
      int m = n.length();
      
      for(int i=0;i<m;i++)
      {
        if(mx < n[i])
        {
          mx = n[i];
          count = (int) mx - 48;
        }
           
      }
        
      
      return count;
    }
};