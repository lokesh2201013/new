class Solution {
public:
    int maxSubArray(vector<int>& n) {
        if (n.empty()) {
            return 0;  // Edge case: empty array
        }

        int c = n[0];  
        int m = n[0];  

        for (int i = 1; i < n.size(); ++i) {
            c = max(n[i], c + n[i]);
            m = max(m, c);
        }

        return m;
    }
};
