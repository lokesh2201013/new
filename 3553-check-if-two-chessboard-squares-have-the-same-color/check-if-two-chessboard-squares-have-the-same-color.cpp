class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int co0 = 0, co1 = 0;
        
        if (((c1[0] - 'a' + 1) % 2 == 0 && (c1[1] - '0') % 2 == 0) ||
            ((c1[0] - 'a' + 1) % 2 != 0 && (c1[1] - '0') % 2 != 0)) {
            co0 = 0;
        } else {
            co0 = 1;
        }
        
        if (((c2[0] - 'a' + 1) % 2 == 0 && (c2[1] - '0') % 2 == 0) ||
            ((c2[0] - 'a' + 1) % 2 != 0 && (c2[1] - '0') % 2 != 0)) {
            co1 = 0;
        } else {
            co1 = 1;
        }
        
        return co1 == co0 ? 1 : 0;
    }
};
