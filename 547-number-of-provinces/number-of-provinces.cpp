class Solution {
public:
    void dfs(vector<vector<int>>& a, vector<bool>& vis, int i) {
        vis[i] = true;
        for (int neighbor : a[i]) { 
            if (!vis[neighbor]) {
                dfs(a, vis, neighbor);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& is) {
        int n = is.size();
        vector<vector<int>> a(n); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (is[i][j] == 1) {
                    a[i].push_back(j);
                }
            }
        }
        int c = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(a, vis, i);
                c++;
            }
        }
        return c;
    }
};