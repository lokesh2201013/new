class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& g, vector<vector<int>>& v) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] == 0 || v[i][j] == 1) return;
        v[i][j] = 1; // Mark the cell as visited
        dfs(i + 1, j, g, v);
        dfs(i - 1, j, g, v);
        dfs(i, j - 1, g, v);
        dfs(i, j + 1, g, v);
    }

    int numEnclaves(vector<vector<int>>& g) {
        int c = 0;
        vector<vector<int>> v(g.size(), vector<int>(g[0].size(), 0));

        // Mark all boundary-connected land cells
        for (int i = 0; i < g[0].size(); i++) {
            if (g[0][i] == 1 && v[0][i] == 0) dfs(0, i, g, v);
            if (g[g.size() - 1][i] == 1 && v[g.size() - 1][i] == 0) dfs(g.size() - 1, i, g, v);
        }
        for (int i = 0; i < g.size(); i++) {
            if (g[i][0] == 1 && v[i][0] == 0) dfs(i, 0, g, v);
            if (g[i][g[0].size() - 1] == 1 && v[i][g[0].size() - 1] == 0) dfs(i, g[0].size() - 1, g, v);
        }

        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                if (g[i][j] == 1 && v[i][j] == 0) c++;
            }
        }
        return c;
    }
};
