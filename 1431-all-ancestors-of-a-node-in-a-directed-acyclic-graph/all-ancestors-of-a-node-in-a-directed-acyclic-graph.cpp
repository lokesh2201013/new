
class Solution {
public:
    void dfs(int s, vector<vector<int>>& v, vector<bool>& vis) {
        vis[s] = true;
        for (int i = 0; i < v[s].size(); i++) {
            if (!vis[v[s][i]]) {
                dfs(v[s][i], v, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> m(n);
        for (int i = 0; i < edges.size(); i++) {
            m[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            dfs(i, m, vis);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (vis[j]) {
                    a[j].push_back(i);
                }
            }
        }
        return a;
    }
};