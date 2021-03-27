class Solution {
public:
    int maxCoins(vector<int>& piles) {
      
      sort(piles.begin(),piles.end(),greater<int>());
      int res = 0;
      int n = piles.size();
      for(int i=1;i<(n/3)*2;i+=2)
      {
        res += piles[i];
      }
      // for(auto a:piles) cout<<a<<" ";
      // cout<<endl;
      return res;
        
    }
};