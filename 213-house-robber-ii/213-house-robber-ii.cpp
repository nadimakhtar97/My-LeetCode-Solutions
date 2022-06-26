class Solution {
public:
    
    int maxLoot(vector<int> nums){
        
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        
        for(int i=1;i<n;i++){
            
            int taken = nums[i];
            if(i-2 >= 0)
                taken += dp[i-2];
            int notTaken = dp[i-1];
            dp[i] = max(taken, notTaken);
            
        }
        
        return dp[n-1];
        
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        
        for(auto& a : nums1)
            cout<<a<<" ";
        cout<<endl;
        
        for(auto& a : nums2)
           cout<<a<<" ";
        cout<<endl;
        
        int ans1 = maxLoot(nums1);
        int ans2 = maxLoot(nums2);
        
        return max(ans1,ans2);
        
        
    }
};