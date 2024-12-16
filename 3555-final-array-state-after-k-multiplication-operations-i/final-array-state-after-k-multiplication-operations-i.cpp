class Solution {
public:
    vector<int> getFinalState(vector<int>& n, int k, int m) {
        for (int i = 0; i < k; i++) {
            int s = *min_element(n.begin(), n.end());
            for (int j = 0; j < n.size(); j++) {
                if (n[j] == s) {
                    n[j] *= m;
                    break;
                }
            }
        }
        return n;
    }
};