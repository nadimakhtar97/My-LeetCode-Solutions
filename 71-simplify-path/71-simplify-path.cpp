class Solution {
public:
    string simplifyPath(string path) {
        
        
        vector<string> s;
        stringstream ss(path);
        string token;
        string ans = "";
        
        while(getline(ss,token,'/')){
            if(token == ".." and !s.empty()){
                s.pop_back();
            }
            else if(token == "."){
                continue;
            }
            else if(token != "" and token != ".." and token != "."){
                s.push_back("/" +token);
            }
        }
        
        
        for(auto a : s){
            ans += a;
        }
        
        if(ans == "")
            ans = "/";
        
        return ans;
    }
};