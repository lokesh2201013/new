class Solution {
public:
    int give(vector<int>& n, vector<vector<int>>& dp, int i, int p) {
        if (i == n.size()) {
            return 0;
        }
        if (dp[i][p + 1] != -1) return dp[i][p + 1]; 

        int withoutCurrent = give(n, dp, i + 1, p);
        int withCurrent = 0;
        if (p == -1 || n[i] > n[p]) {
            withCurrent = 1 + give(n, dp, i + 1, i);
        }
        return dp[i][p + 1] = max(withCurrent, withoutCurrent);
    }

    int lengthOfLIS(vector<int>& n) {
        int sz = n.size();
        vector<vector<int>> dp(sz, vector<int>(sz + 1, -1)); 
        return give(n, dp, 0, -1);
    }
};
