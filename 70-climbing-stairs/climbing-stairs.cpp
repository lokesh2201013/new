class Solution {
public:
    int give(int n, vector<int>& dp, int i) {
        if (i == n) return 1;
        if (i > n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int l = give(n, dp, i + 1);
        int r = give(n, dp, i + 2);
        dp[i] = l + r;
        
        return dp[i];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return give(n, dp, 0);
    }
};