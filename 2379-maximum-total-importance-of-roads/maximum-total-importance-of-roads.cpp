class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& r) {
        vector<int> d(n, 0);
        
        for (const auto& e : r) {
            d[e[0]]++;
            d[e[1]]++;
        }
        
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = i;
        }
        
        sort(c.begin(), c.end(), [&](int a, int b) {
            return d[a] > d[b];
        });
        
        long long t = 0;
        for (int i = 0; i < n; i++) {
            t += (long long)(n - i) * d[c[i]];
        }
        
        return t;
    }
};
