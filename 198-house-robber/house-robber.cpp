class Solution {
public:
    int give(vector<int>& n, vector<int>& dp, int i) {
        if (i >= n.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int l = give(n, dp, i + 1); 
        int r = give(n, dp, i + 2) + n[i];

        return dp[i] = max(l, r);
    }

    int rob(vector<int>& n) {
        vector<int> dp(n.size(), -1);
        return give(n, dp, 0);
    }
};
