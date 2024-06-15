class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n = m.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; ++j) {
            dp[0][j] = m[0][j];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int minPrev = dp[i-1][j];
                if (j > 0) minPrev = min(minPrev, dp[i-1][j-1]);
                if (j < n-1) minPrev = min(minPrev, dp[i-1][j+1]);
                
                dp[i][j] = m[i][j] + minPrev;
            }
        }
        
        int minPathSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minPathSum = min(minPathSum, dp[n-1][j]);
        }
        
        return minPathSum;
    }
};
