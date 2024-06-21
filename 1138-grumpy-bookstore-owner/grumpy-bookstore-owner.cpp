class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int mi) {
        int n = c.size();
        int bc = 0;
        
        for (int i = 0; i < n; ++i) {
            if (g[i] == 0) {
                bc += c[i];
            }
        }
        
        int es = 0;
        for (int i = 0; i < mi; ++i) {
            if (g[i] == 1) {
                es += c[i];
            }
        }
        
        int mxs = es;
        for (int i = mi; i < n; ++i) {
            if (g[i] == 1) {
                es += c[i];
            }
            if (g[i - mi] == 1) {
                es -= c[i - mi];
            }
            mxs = max(mxs, es);
        }
        
        return bc + mxs;
    }
};
