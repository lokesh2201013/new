#include <vector>

class Solution {
private:
    int give(int i, int j, std::vector<std::vector<int>>& dp, const std::vector<std::vector<int>>& o) {
        if (i >= 0 && j >= 0 && o[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int up = give(i - 1, j, dp, o);
        int left = give(i, j - 1, dp, o);
        
        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        
        return give(m - 1, n - 1, dp, o);
    }
};
