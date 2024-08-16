class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
    
        int delr[] = {-1, 1, 0, 0};
        int delc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            q.pop();
            dis[r][c] = s;
            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, s + 1});
                }
            }
        }
        return dis;
    }
};
