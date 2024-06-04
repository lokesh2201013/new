class Solution {
private:
    int give(vector<int>& n, int i, vector<int>& dp) {
        if (i < 0) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];

        int include = n[i] + give(n, i - 2, dp);
        int exclude = give(n, i - 1, dp);

        return dp[i] = max(include, exclude);
    }

    int robLinear(vector<int>& n) {
        int size = n.size();
        vector<int> dp(size, -1);
        return give(n, size - 1, dp);
    }

public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];

        vector<int> t1, t2;
        for (int i = 0; i < size; i++) {
            if (i != 0) t1.push_back(nums[i]); 
            if (i != size - 1) t2.push_back(nums[i]);
        }

        return max(robLinear(t1), robLinear(t2));
    }
};
