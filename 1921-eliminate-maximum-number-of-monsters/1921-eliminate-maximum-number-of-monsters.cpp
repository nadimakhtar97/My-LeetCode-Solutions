class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = dist.size();
        int count = 1;
        vector<float> time;
        
        for(int i=0;i<n;i++){
            
            time.push_back(((float)dist[i]/speed[i]));
        }
        
        sort(time.begin(),time.end());
        
        for(int i=0;i<n-1;i++){
            if(time[i+1]-time[i]>=1 or (time[i+1] > count)){
                count++;
            }else{
                break;
            }
        }
        
        for(auto a : time) cout<<a<<" ";
        cout<<endl;
        
        return count;
    }
};