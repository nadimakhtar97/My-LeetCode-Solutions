// RE-ROOTING OF TREES

class Solution {
public:
    
    vector<int> subTreeSize;
    vector<int> subTreeAns;
    vector<int> dp;
    vector<vector<int>> gr;
    
    void dfs1(int cur,int par){
        
        subTreeSize[cur] = 1;
        
        for(auto& nbr : gr[cur]){
            
            if(nbr != par){
                // cout<<cur<<endl;
                dfs1(nbr,cur);
                subTreeSize[cur] += subTreeSize[nbr];
                subTreeAns[cur] += subTreeAns[nbr] + subTreeSize[nbr];
                
            }
        }
        
    }
    
    
    void dfs2(int cur,int par){
        
        dp[cur] = subTreeAns[cur];
        
        for(auto& nbr : gr[cur]){
            
            if( nbr != par){
            // detach step
            subTreeAns[cur] -= subTreeAns[nbr];
            subTreeAns[cur] -= subTreeSize[nbr];
            subTreeSize[cur] -= subTreeSize[nbr];
            
            
            // attach step
            subTreeSize[nbr] += subTreeSize[cur];
            subTreeAns[nbr] += subTreeAns[cur];
            subTreeAns[nbr] += subTreeSize[cur];
            
            dfs2(nbr,cur);
            
            // rollback step
            subTreeSize[nbr] -= subTreeSize[cur];
            subTreeAns[nbr] -= subTreeAns[cur];
            subTreeAns[nbr] -= subTreeSize[cur];
            
            subTreeSize[cur] += subTreeSize[nbr];
            subTreeAns[cur] += subTreeAns[nbr];
            subTreeAns[cur] += subTreeSize[nbr];
            
            
                
            }
            
        }
        
    }
    
    
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        subTreeSize.resize(n,0);
        subTreeAns.resize(n,0);
        dp.resize(n);
        gr.resize(n,vector<int>());
        
        vector<int> temp;
        
        
        for(auto& e : edges){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        
        
        
        dfs1(0,-1);
        
        dfs2(0,-1);
        
        return dp;
        
        
    }
};