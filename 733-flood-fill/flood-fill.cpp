class Solution {
public:
    void dfs(int c, int sr, int sc, vector<vector<int>>& im, int s) {
        if (sr < 0 || sr >= im.size() || sc < 0 || sc >= im[0].size() || im[sr][sc] != s || im[sr][sc] == c) {
            return;
        }

        im[sr][sc] = c;

        dfs(c, sr + 1, sc, im, s);
        dfs(c, sr - 1, sc, im, s);
        dfs(c, sr, sc + 1, im, s);
        dfs(c, sr, sc - 1, im, s);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int c) {
        int s = im[sr][sc];
        if (s != c) {
            dfs(c, sr, sc, im, s);
        }
        return im;
    }
};
