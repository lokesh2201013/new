#include <vector>
#include <algorithm>

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int wi) {
        vector<int> w;
        int c = 1;
        for (int i = 0; i < p.size(); i++) {
            w.push_back(p[i][0]);
        }
        sort(w.begin(), w.end());
        int prev_end = w[0] + wi;
        for (int i = 1; i < w.size(); i++) {
            if (w[i] <= prev_end) {
                continue;
            } else {
                prev_end = w[i] + wi;
                c++;
            }
        }
        return c;
    }
};
