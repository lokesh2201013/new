class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        // Create a matrix of optional<int> initialized with nullopt
        vector<vector<optional<int>>> c(m.size(), vector<optional<int>>(m[0].size(), nullopt));
        
        // Copy values from `m` to `c`
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                c[i][j] = m[i][j];
            }
        }
        for (int i = 0; i < c.size(); i++) {
            for (int j = 0; j < c[0].size(); j++) {
                if (c[i][j].has_value() && c[i][j].value() == 0) {
                    for (int k = 0; k < c.size(); k++) {
                        if (c[k][j].has_value() && c[k][j].value() != 0) c[k][j] = nullopt;
                    }
                    for (int k = 0; k < c[0].size(); k++) {
                        if (c[i][k].has_value() && c[i][k].value() != 0) c[i][k] = nullopt;
                    }
                }
            }
        }
        
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (!c[i][j].has_value()) {
                    m[i][j] = 0;
                }
            }
        }
    }
};
