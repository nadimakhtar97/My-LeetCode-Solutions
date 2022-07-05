class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int maxLen = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        
        for(auto& a : s){         
            if(s.count(a-1) == 0){
                int y = a + 1;
                while(s.count(y))
                    y++;
                maxLen = max(maxLen,y-a);
            }
        }
        
        
        return maxLen;
    }
};