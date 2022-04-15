class Solution {
public:
    
    
    
    // -------------------------------------------
    
    vector<int> memo;
    
    int minCost(int n,vector<int>& cost){
        
        if(n == 0 or n == 1)
            return cost[n];
        
        
        if(n < 0)
            return 0;
        
        
        if(memo[n] != -1)
            return memo[n];
        
        int i = minCost(n-1,cost);
        int j = minCost(n-2,cost);
        
        return memo[n] = min(i,j)+cost[n];
        
        
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        memo.resize(n,-1);
        int res = min(minCost(n-1,cost),minCost(n-2,cost));
        return res;
    }
};