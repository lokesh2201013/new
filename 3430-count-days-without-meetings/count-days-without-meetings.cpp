class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        vector<vector<int>> a;
        sort(m.begin(), m.end());
        
        for(int i = 0; i < m.size(); i++) {
            if(a.empty() || m[i][0] > a.back()[1]) {
                a.push_back(m[i]);
            } else {
                a.back()[1] = max(a.back()[1], m[i][1]);
            }
        }
        
        int c = 0;
        for(int i = 0; i < a.size(); i++) {
            c += a[i][1] - a[i][0] + 1; 
        }
        
        return d - c;
    }
};