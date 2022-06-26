class Solution
{
    public:
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n,-1);
            int ans = robRecursion(nums,n-1,dp);
            return ans;
        }
    
        
        int robRecursion(vector<int>& nums,int idx,vector<int>& dp){
            
            if(idx == 0) return nums[idx];
            
            if(idx < 0)  return 0;
            
            if(dp[idx] != -1) return dp[idx];
            
            
            int pick = nums[idx] + robRecursion(nums,idx-2,dp);
            
            int notPick = robRecursion(nums,idx-1,dp);
            
            return dp[idx] = max(pick,notPick);
            
            
        }
};