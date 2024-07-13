class Solution {
public:
    int f(vector<int>& p, vector<vector<vector<int>>>& dp, int i, int b, int cap) {
        if (i == p.size() || cap == 0) return 0;
        if (dp[i][b][cap] != -1) return dp[i][b][cap];
        
        int profit;
        if (!b) {
            profit = max(-p[i] + f(p, dp, i+1, 1, cap), f(p, dp, i+1, 0, cap));
        } else {
            profit = max(p[i] + f(p, dp, i+1, 0, cap-1), f(p, dp, i+1, 1, cap));
        }
        return dp[i][b][cap] = profit;
    }

    int maxProfit(int k,vector<int>& p) {
        int n = p.size();
        int cap = k;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap+1, -1)));
        return f(p, dp, 0, 0, cap);
    }
};
