class Solution {
public:
bool is(int i, int j, int rows, int cols) {
    return i == 0 || i == rows - 1 || j == 0 || j == cols - 1;
}
void dfs(vector<vector<int>>& v, const vector<vector<char>>& b, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || v[i][j] != 0 || b[i][j] == 'X')
    {
        return;
    }
    v[i][j] = -1;
    dfs(v, b, i+1, j, n, m);
    dfs(v, b, i, j-1, n, m);
    dfs(v, b, i-1, j, n, m);
    dfs(v, b, i, j+1, n, m);
}
  void solve(vector<vector<char>>& b) {
    int n = b.size();
    if (n == 0) return;
    int m = b[0].size();
    vector<vector<int>> v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 'O' && is(i, j, n, m)) {
                dfs(v, b, i, j, n, m);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 'O' && v[i][j] != -1) {
                b[i][j] = 'X';
            }
        }
    }
}};