class Solution {
public:
    int give(int i, vector<int>& n, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];
        int rob = n[i] + give(i - 2, n, dp);
        int notRob = give(i - 1, n, dp);
        return dp[i] = max(rob, notRob);
    }

    int rob(vector<int>& n) {
        vector<int> dp(n.size(), -1);
        return give(n.size() - 1, n, dp);
    }
};
