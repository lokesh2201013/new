class Solution {
    void mark(vector<vector<char>>& m, int x, int y, int r, int c) {
        if (x < 0 || y < 0 || x >= r || y >= c || m[x][y] != '1') {
            return;
        }
        m[x][y] = '2';
        mark(m, x + 1, y, r, c);
        mark(m, x - 1, y, r, c);
        mark(m, x, y - 1, r, c);
        mark(m, x, y + 1, r, c);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    mark(grid, i, j, r, c);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
