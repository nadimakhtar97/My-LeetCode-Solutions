class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        int maxLen = 0;
        string lps = "";
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                
                if(g==0){
                    t[i][j] = true;
                }else if(g==1){
                    if(s[i]==s[j])
                        t[i][j] = true;
                }else{
                    if(s[i]==s[j] and t[i+1][j-1])
                        t[i][j] = true;
                }
                
                if(t[i][j])
                    maxLen = g+1;
            }
        }
        
        for(int i=0,j=maxLen-1;j<n;j++,i++){
            
            if(t[i][j])
            {
                for(int k=i;k<=j;k++){
                    
                    lps += s[k];
                    
                }
                    break;
            }
            
        }
        
        cout<<maxLen;
        
        return lps;
        
        
    }
};