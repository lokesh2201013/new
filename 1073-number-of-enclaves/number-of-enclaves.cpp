class Solution {
public:
    bool isBoundary(int i, int j, int rows, int cols) {
        return i == 0 || i == rows - 1 || j == 0 || j == cols - 1;
    }

    void dfs(vector<vector<int>>& v, const vector<vector<int>>& b, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || v[i][j] != 0 || b[i][j] == 0) {
            return;
        }
        v[i][j] = -1;
        dfs(v, b, i + 1, j, n, m);
        dfs(v, b, i, j - 1, n, m);
        dfs(v, b, i - 1, j, n, m);
        dfs(v, b, i, j + 1, n, m);
    }

    int numEnclaves(vector<vector<int>>& b) {
        int n = b.size();
        if (n == 0) return 0;
        int m = b[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 1 && isBoundary(i, j, n, m)) {
                    dfs(v, b, i, j, n, m);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 1 && v[i][j] != -1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
