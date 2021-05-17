class Solution {
public:
    string truncateSentence(string s, int k) {
        
        int n = s.length();
        int countSpace = 0;
        int i=0;
        
        for(;i<n;i++)
        {
            if(s[i]==' ')
                countSpace++;
            if(countSpace==k)
                break;
        }
        
        return s.substr(0,i);
        
    }
};