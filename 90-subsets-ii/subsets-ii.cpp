class Solution {
private:
    void give(vector<vector<int>>& a, vector<int>& s, vector<int>& n, int i, int ni) {
        if (i == ni) {
            a.push_back(s);
            return;
        }
        s.push_back(n[i]);
        give(a, s, n, i + 1, ni);
        s.pop_back();  
        give(a, s, n, i + 1, ni);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& n) {
        vector<vector<int>> a;
        vector<int> s;
        sort(n.begin(),n.end());
        int ni = n.size();
        
        give(a, s, n, 0, ni);

        set<vector<int>> uniqueSubsets(a.begin(), a.end());
        a.assign(uniqueSubsets.begin(), uniqueSubsets.end());

        return a;
    }
};
