class Solution {
private:
    int f(int i, int j1, int j2, vector<vector<int>>& g, vector<vector<vector<int>>>& dp, int r, int c) {
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;
        if (i == r - 1) {
            if (j1 == j2) return g[i][j1];
            else return g[i][j1] + g[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int value = 0;
                if (j1 == j2) value = g[i][j1];
                else value = g[i][j1] + g[i][j2];
                value += f(i + 1, j1 + d1, j2 + d2, g, dp, r, c);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return f(0, 0, c - 1, grid, dp, r, c);
    }
};
