class Solution {
public:
    int give(vector<vector<int>>& dp, vector<int>& p, int buy, int i) {
        if (i >= p.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        
        int prof = 0;
        if (buy) {
            prof = max(-p[i] + give(dp, p, 0, i + 1), give(dp, p, 1, i + 1));
        } else {
            prof = max(p[i] + give(dp, p, 1, i + 2), give(dp, p, 0, i + 1));
        }
        
        return dp[i][buy] = prof;
    }

    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size(), vector<int>(2, -1));
        return give(dp, p, 1, 0);
    }
};
