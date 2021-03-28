class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      
      map<int,int> freq;
      set<int> unique;
      
      for(auto& a:arr)
        freq[a]++;
      
      for(auto& p:freq)
        unique.insert(p.second);
      
      return freq.size()==unique.size();
        
    }
};