class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
        priority_queue<int> pq(nums.begin(),nums.end());
        
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        cout<<f<<" "<<s<<endl;
        
        return ((f-1)*(s-1));
    }
};