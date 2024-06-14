class Solution {
private:
    long long give(const std::vector<std::vector<int>>& g, std::vector<std::vector<long long>>& dp, int i, int j) {
        if (i == 0 && j == 0) return g[0][0];
        if (i < 0 || j < 0) return LLONG_MAX;
        if (dp[i][j] != -1) return dp[i][j];
        
        long long u = (i > 0 ? give(g, dp, i - 1, j) : LLONG_MAX);
        long long l = (j > 0 ? give(g, dp, i, j - 1) : LLONG_MAX);
        
        if (u != LLONG_MAX) u += g[i][j];
        if (l != LLONG_MAX) l += g[i][j];
        
        return dp[i][j] = std::min(u, l);
    }

public:
    int minPathSum(std::vector<std::vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, -1));
        
        return static_cast<int>(give(g, dp, m - 1, n - 1));
    }
};
