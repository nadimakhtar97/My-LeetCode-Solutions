class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        int n = s.length();
        
        
        for(auto& c : s){
            
            if(stk.empty())
                stk.push(c);
            else{
                
                char top = stk.top();
                if( (top == '(' and c == ')') or (top == '[' and c == ']') or (top =='{' and c == '}'))
                    stk.pop();
                else
                    stk.push(c);

            }
        }
        
        
        return stk.empty();
        
    }
};