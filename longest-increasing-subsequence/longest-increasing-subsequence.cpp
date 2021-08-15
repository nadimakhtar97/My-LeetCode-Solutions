class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,0);
        int length = 0;
        
        for(int i=0;i<n;i++){
            int mx = 0;
            
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    mx = max(dp[j],mx);
                }
            }
            
            dp[i] = mx+1;
            
            if(dp[i]>length){
                length = dp[i];
            }
        }
        
        return length;
        
    }
};