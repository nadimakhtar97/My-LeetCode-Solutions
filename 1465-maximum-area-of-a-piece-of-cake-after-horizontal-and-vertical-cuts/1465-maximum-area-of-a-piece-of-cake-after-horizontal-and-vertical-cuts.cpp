class Solution
{
    public:
        int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
        {

            int mod = 1e9 + 7;
            sort(horizontalCuts.begin(), horizontalCuts.end());
            sort(verticalCuts.begin(), verticalCuts.end());

            if (find(horizontalCuts.begin(), horizontalCuts.end(), h) == horizontalCuts.end())
            {
                horizontalCuts.push_back(h);
            }

            if (find(verticalCuts.begin(), verticalCuts.end(), w) == verticalCuts.end())
            {
                verticalCuts.push_back(w);
            }
            
            long long currRow = 0;
            long long nextRow = horizontalCuts[0];
            long long maxWidth = abs(currRow - nextRow);
            long long n = horizontalCuts.size();
            long long m = verticalCuts.size();


            
            // for(auto& a : horizontalCuts) cout<<a<<" ";
            // cout<<endl;
            
            // for(auto& a : verticalCuts) cout<<a<<" ";
            // cout<<endl;

            for (int i = 1; i < n; i++)
            {
                currRow = nextRow;
                nextRow = horizontalCuts[i];
                maxWidth = max(maxWidth, abs(currRow - nextRow));
            }

            long long currCol = 0;
            long long nextCol = verticalCuts[0];
            long long maxHeight = abs(currCol - nextCol);

            for (int i = 1; i < m; i++)
            {
                currCol = nextCol;
                nextCol = verticalCuts[i];
                maxHeight = max(maxHeight, abs(currCol - nextCol));
            }

            // cout << "maxWidth = " << maxWidth << " maxHeight = " << maxHeight << endl;

            int ans = ((maxHeight % mod) *(maxWidth % mod)) % mod;

            return ans;
        }
};