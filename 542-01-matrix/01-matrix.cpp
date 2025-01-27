class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        vector<vector<int>> v(m.size(), vector<int>(m[0].size(), 0));
        vector<vector<int>> d(m.size(), vector<int>(m[0].size(), 0));
        queue<pair<pair<int, int>, int>> q; 

        for (int i = 0; i < m.size(); i++) {  
            for (int j = 0; j < m[0].size(); j++) {
                if (m[i][j] == 0) { 
                    q.push({{i, j}, 0});
                    v[i][j] = 1; 
                }
            }
        }
        vector<int> dr = {-1, 0, 1, 0}; 
        vector<int> dc = {0, 1, 0, -1}; 
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            q.pop();
            d[r][c] = s;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m.size() && nc >= 0 && nc < m[0].size() && v[nr][nc] != 1) {
                    q.push({{nr, nc}, s + 1});
                    v[nr][nc] = 1; 
                }
            }
        }
        return d;
    }
};
