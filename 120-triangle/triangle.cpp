class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        if (t.empty()) return 0;

        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the last row of dp with the last row of triangle
        for (int j = 0; j < n; ++j) {
            dp[n-1][j] = t[n-1][j];
        }

        // Fill dp array from bottom to top
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = t[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};
