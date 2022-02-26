class Solution {
public:
    
    void letterCombinations(int index, string comb,string& digits,vector<vector<char>>& keypad,vector<string>& res){
        
        
        if(comb.length() == digits.length()){
            res.push_back(comb);
            return;
        }
        
        int digit = digits[index] - '2';
        
//         for(int i=0;i<keypad[digit].size();i++){
            
//             comb += keypad[index-1][i];
//             letterCombinations(index+1,comb,digits,keypad,res);
//             comb -= keypad[index-1][i];
//         }
        
        for(auto c : keypad[digit]){
            letterCombinations(index+1,comb+c,digits,keypad,res);
        }
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<vector<char>> keypad = {
                                       {'a','b','c'},
                                       {'d','e','f'},
                                       {'g','h','i'},
                                       {'j','k','l'},
                                       {'m','n','o'},
                                       {'p','q','r','s'},
                                       {'t','u','v'},
                                       {'w','x','y','z'}
                                      };
        
        vector<string> res;
        
        if(digits.length() == 0)
            return res;
        
        letterCombinations(0,"",digits,keypad,res);
        
        return res;
    }
};