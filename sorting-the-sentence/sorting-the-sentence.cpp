class Solution {
public:
    string sortSentence(string s) {
        
        stringstream ss(s);
        string word;
        string res;
        vector<pair<int,string>> v;
        
        while(ss>>word)
        {
            int len = word.length();
            int i = int(word[len-1]) - 48;
            v.push_back({i,word.substr(0,len-1)});
        }
        
        sort(v.begin(),v.end());
        
        
        int n = v.size();
        for(int i = 0;i<n;i++)
        {
            res += v[i].second;
            if(i != n-1)
                res += " ";
        }
    
        return res;
        
        
    }
};