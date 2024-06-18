class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<vector<int>> m(d.size(), vector<int>(2));
        for (int i = 0; i < d.size(); i++) {
            m[i][0] = p[i];
            m[i][1] = d[i];
        }
        sort(m.begin(), m.end());
        sort(w.begin(), w.end());
        reverse(m.begin(), m.end());
        int c = 0;
        for (int i = 0; i < w.size(); i++) {
            int j = 0;
            while (j < m.size()) {
                if (w[i] >= m[j][1]) {
                    c += m[j][0];
                    break;
                } else {
                    j++;
                }
            }
        }
        return c;
    }
};
