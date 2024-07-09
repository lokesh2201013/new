class Solution {
public:
    int give(vector<int>& n, vector<int>& dp, int i) {
        if (i < 0) return 0;
        if (i == 0) return n[0];
        if (dp[i] != -1) return dp[i];
        
        int robCurrent = n[i] + give(n, dp, i - 2);
        int skipCurrent = give(n, dp, i - 1);
        
        return dp[i] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& n) {
        if (n.size() == 0) return 0;
        if (n.size() == 1) return n[0];
        
        vector<int> dp(n.size(), -1);
        return give(n, dp, n.size() - 1);
    }
};
