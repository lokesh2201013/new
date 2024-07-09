class Solution {
public:
    int give(const string &t1, const string &t2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (t1[i] == t2[j]) {
            dp[i][j] = 1 + give(t1, t2, i - 1, j - 1, dp);
        } else {
            dp[i][j] = max(give(t1, t2, i, j - 1, dp), give(t1, t2, i - 1, j, dp));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return give(t1, t2, m - 1, n - 1, dp);
    }
};
