class Solution {
public:
    void give(vector<vector<int>>& a, vector<int>& n, vector<int>& p, int i) {
        if (i == n.size()) {
            a.push_back(p);
            return;
        }
        
        p.push_back(n[i]);
        give(a, n, p, i + 1);
     
        p.pop_back();
        give(a, n, p, i + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>> a;
        vector<int> p;
        give(a, n, p, 0);
        return a;
    }
};
