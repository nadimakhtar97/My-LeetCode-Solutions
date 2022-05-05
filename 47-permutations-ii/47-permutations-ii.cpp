class Solution {
public:
    
    
    
    
    void fun(vector<int>& nums,vector<bool> used,vector<int>perm,vector<vector<int>>& res){
        
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(used[i] == true) continue;
            
            if(i>0 and nums[i]==nums[i-1] and used[i-1] == false) continue;
            
            used[i] = true;
            perm.push_back(nums[i]);
            fun(nums,used,perm,res);
            used[i] = false;
            perm.pop_back();
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> used(n,false);
        sort(nums.begin(),nums.end());
        
        fun(nums,used,perm,res);
        
        return res;
        
    }
};