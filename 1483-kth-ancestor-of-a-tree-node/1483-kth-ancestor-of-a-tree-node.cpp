class TreeAncestor {
public:
    
    vector<vector<int>> dp;
    int m;
    int nodeCount;
    TreeAncestor(int n, vector<int>& parent) {
        
        m = log2(n)+1;
        nodeCount = n;
        dp.resize(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            dp[i][0] = parent[i];
        }
        
        // filling sparse table by using dp
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                
                if(dp[i][j-1] == -1){
                    dp[i][j] = -1;
                }else{
                    dp[i][j] = dp[dp[i][j-1]][j-1];
                }
            }
        }
        
        // for(auto& a : dp){
        //     for(auto& b : a){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int getKthAncestor(int node, int k) {
        
        if(k>=nodeCount)
            return -1;
        
        for(int i=m-1;i>=0;i--){
            if((k>>i)&1){
                if(node == -1)
                    return node;
                node = dp[node][i];
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */