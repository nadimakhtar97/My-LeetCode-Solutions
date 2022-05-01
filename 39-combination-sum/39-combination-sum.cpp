class Solution {
public:
    
    
    void combinationSum(int index,vector<int>& candidates, int target,vector<int> comb,vector<vector<int>>& combinations){
        
        if(target == 0){
            combinations.push_back(comb);
            return;
        }
        
        if(target < 0 or index == candidates.size())
            return;
        
        
        combinationSum(index+1,candidates,target,comb,combinations);
        
        comb.push_back(candidates[index]);
        combinationSum(index,candidates,target-candidates[index],comb,combinations);
        
        
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> combinations;
        
        combinationSum(0,candidates,target,vector<int>(),combinations);
        
        return combinations;
    }
};