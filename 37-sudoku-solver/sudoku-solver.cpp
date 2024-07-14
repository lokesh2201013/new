class Solution {
public:
    bool s(vector<vector<char>>& b) {
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[0].size(); j++) {
                if (b[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (valid(b, i, j, c)) {
                            b[i][j] = c;
                            if (s(b)) return true;
                            else b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(vector<vector<char>>& b, int r, int co, char c) {
        for (int i = 0; i < 9; i++) {
            if (b[i][co] == c) return false;
            if (b[r][i] == c) return false;
            if (b[3 * (r / 3) + i / 3][3 * (co / 3) + i % 3] == c) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& b) {
        s(b);
    }
};
