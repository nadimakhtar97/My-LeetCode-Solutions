class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
      vector<pair<int,int>> v;
      vector<int> res;
      for(auto a : arr)
      {
        int temp = a;
        int count = 0;
        while(temp)
        {
          int lsb = temp&1;
          temp >>= 1;
          if(lsb)
            count++;
        }
        v.push_back({count,a});
      }
        
      sort(v.begin(),v.end());
      for(auto p : v)
        res.push_back(p.second);
      
      return res;
    }
};