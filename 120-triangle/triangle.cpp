class Solution {
private:
    int give(vector<vector<int>>& t, vector<vector<int>>& dp, int i, int j) {
        if (i == t.size() - 1) return t[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int d = t[i][j] + give(t, dp, i + 1, j);
        int dg = t[i][j] + give(t, dp, i + 1, j + 1);

        return dp[i][j] = min(d, dg);
    }

public:
    int minimumTotal(vector<vector<int>>& t) {
        if (t.empty()) return 0;
        vector<vector<int>> dp(t.size(), vector<int>(t.size(), -1));
        return give(t, dp, 0, 0);
    }
};
