class Solution {
public:
    bool dfs(int n, int col, vector<int>& c, vector<vector<int>>& g) {
        c[n] = col;
        for (auto it : g[n]) {
            if (c[it] == -1) {
                if (!dfs(it, !col, c, g)) return false;
            } else if (c[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& g) {
        int v = g.size();
        vector<int> c(v, -1);
        for (int i = 0; i < v; i++) {
            if (c[i] == -1) {
                if (!dfs(i, 0, c, g)) return false;
            }
        }
        return true;
    }
};
