class Solution {
    int give(int n, vector<int>& dp) {
        if (n <= 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = give(n - 1, dp) + give(n - 2, dp);
    }
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return give(n, dp);
    }
};