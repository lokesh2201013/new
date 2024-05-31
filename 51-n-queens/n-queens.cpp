class Solution {
private:
    bool isValid(int r, int c, vector<string>& b, int n) {
      
        int dr = r, dc = c;
        while (r >= 0 && c >= 0) {
            if (b[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }
        r = dr;
        c = dc;
        while (c >= 0) {
            if (b[r][c] == 'Q') {
                return false;
            }
            c--;
        }

        // Check lower diagonal
        r = dr;
        c = dc;
        while (r < n && c >= 0) {
            if (b[r][c] == 'Q') {
                return false;
            }
            r++;
            c--;
        }

        return true;
    }

    void solve(int c, vector<string>& b, vector<vector<string>>& ans, int n) {
        if (c == n) {
            ans.push_back(b);
            return;
        }

        for (int r = 0; r < n; r++) {
            if (isValid(r, c, b, n)) {
                b[r][c] = 'Q';
                solve(c + 1, b, ans, n);
                b[r][c] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n, string(n, '.'));
        solve(0, b, ans, n);
        return ans;
    }
};