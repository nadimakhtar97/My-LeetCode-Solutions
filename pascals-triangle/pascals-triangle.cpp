class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle;
        pascalsTriangle.push_back(vector<int>{1});
        
        for(int i = 2;i<numRows+1;i++)
        {
            vector<int> row;
            row.push_back(1);
            int elementNo = 1;
            while(row.size()!=i-1)
            {   
                int first = pascalsTriangle[i-2][elementNo-1];                
                int second = pascalsTriangle[i-2][elementNo];
                row.push_back(first+second);                
                elementNo++;
            }
            row.push_back(1);
            pascalsTriangle.push_back(row);
        }
        
        
        return pascalsTriangle;   
    }
    
};