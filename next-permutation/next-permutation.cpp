class Solution {
public:
    void nextPermutation(vector<int>& A) {
        
        if(A.size()==1 or A.size()==0)
            return;
        
        int n = A.size();
        int i = n-2;
        
        while(i>=0 and A[i]>=A[i+1]) i--;
        
        if(i>=0){
            int j = n-1;
            while(A[j]<=A[i]){
                j--;
            }
            swap(A[i],A[j]);
        }
        reverse(A.begin()+i+1,A.end());
        
    }
};