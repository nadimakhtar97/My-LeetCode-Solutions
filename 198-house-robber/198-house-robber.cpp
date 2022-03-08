class Solution {
public:
    
    vector<int> memo;
    int maxLoot(int i,int& n,vector<int>& nums){
        
        if( i >= n)
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int loot = max(maxLoot(i+2,n,nums)+nums[i],maxLoot(i+1,n,nums));
        
        return memo[i] = loot;
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        memo.resize(n,-1);
        return maxLoot(0,n,nums);
        
    }
};