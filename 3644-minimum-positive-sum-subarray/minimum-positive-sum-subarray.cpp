class Solution {
public:
    int minimumSumSubarray(vector<int>& n, int l, int r) {
        int minSum = INT_MAX;

        for (int i = 0; i < n.size(); i++) {
            int currentSum = 0;

            for (int j = i; j < n.size(); j++) {
                currentSum += n[j];

                int length = j - i + 1;
                if (length >= l && length <= r&&currentSum>0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }
           if(minSum==INT_MAX)return -1;
        return minSum;
    }
};