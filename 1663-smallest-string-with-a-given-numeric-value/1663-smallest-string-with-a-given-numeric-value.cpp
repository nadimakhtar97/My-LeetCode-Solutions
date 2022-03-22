class Solution {
public:
    
    string getSmallestString(int n, int k) {
        
        string ans(n,'a');
        cout<<ans<<endl;
        k -= n;
        
        while( k > 0){
            
            int c = min(25,k);
            ans[n-1] = c + 'a';
            n--;
            k -=c;
            
        }
        
        return ans;
        
    }
};