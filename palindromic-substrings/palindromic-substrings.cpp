class Solution {
public:
    int countSubstrings(string S) {
    
    int N = S.length();
    vector<vector<bool>> t(N,vector<bool>(N,false));
    int count = 0;
    
    for(int g=0;g<N;g++){
        for(int i = 0,j = g;j<N;j++,i++ ){
            
            if(g==0){
                t[i][j] = true;
            }else if(g==1){
                if(S[i]==S[j])
                    t[i][j] = true;
            }else{
                if(S[i]==S[j] && t[i+1][j-1]){
                    t[i][j]=true;
                }
            }
            
            if(t[i][j])
                count++;
            
        }
    }
    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return count;
        
    }
};