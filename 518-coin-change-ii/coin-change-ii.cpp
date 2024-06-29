class Solution {
    int give(int a, vector<int>& c, vector<vector<int>>& dp, int n) {
        if (a == 0) return 1;
        if (n == 0) return 0;
        if (dp[n][a] != -1) return dp[n][a];
        
        int notTake = give(a, c, dp, n - 1);
        int take = 0;
        if (c[n - 1] <= a) take = give(a - c[n - 1], c, dp, n);

        return dp[n][a] = notTake + take;
    }
public:
    int change(int a, vector<int>& c) {
        vector<vector<int>> dp(c.size() + 1, vector<int>(a + 1, -1));
        return give(a, c, dp, c.size());
    }
};
