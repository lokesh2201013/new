class Solution {
public:
    int f(vector<int>& p, vector<vector<int>>& dp, int i, int b) {
        if (i == p.size()) return  0;
        if (dp[i][b] != -1) return dp[i][b];
        
        int profit;
        if (!b) {
            profit = max(-p[i] + f(p, dp, i+1, 1), f(p, dp, i+1, 0));
        } else {
            profit = max(p[i] + f(p, dp, i+1, 0), f(p, dp, i+1, 1));
        }
        return dp[i][b] = profit;
    }

    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size(), vector<int>(2, -1));
        int b = 0;
        return f(p, dp, 0, b);
    }
};
