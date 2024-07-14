class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        int hs = 1, vs = 1, i = 0, j = 0;
        int ans = 0; 
        sort(h.begin(), h.end(), greater<int>());
        sort(v.begin(), v.end(), greater<int>());
        while (i < h.size() && j < v.size()) {
            if (h[i] >= v[j]) {
                ans += vs * h[i];
                hs++;
                i++;
            } else {
                ans += hs * v[j];
                vs++;
                j++;
            }
        }

        while (i < h.size()) {
            ans += vs * h[i];
            i++;
        }

        while (j < v.size()) {
            ans += hs * v[j];
            j++;
        }
        return ans;
    }
};
