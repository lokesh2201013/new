class Solution {
public:
    int m, n;
    int give(vector<vector<int>>& dp, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        int d = give(dp, i + 1, j);
        int r = give(dp, i, j + 1);
        
        return dp[i][j] = d + r;
    }

    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return give(dp, 0, 0);
    }
};
