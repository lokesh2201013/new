class Solution {
private:
    void give(int i, vector<int>& q, int k, vector<int>& s, vector<vector<int>>& ans, int n) {
        if (s.size() == k) {
            ans.push_back(s);
            return;
        }
        if (i == n) {
            return;
        }
        s.push_back(q[i]);
        give(i + 1, q, k, s, ans, n);
        s.pop_back();
        give(i + 1, q, k, s, ans, n);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> s;
        vector<vector<int>> ans;
        vector<int> q;
        for (int i = 1; i <= n; i++) {
            q.push_back(i);
        }
        give(0, q, k, s, ans, n);
        return ans;
    }
};
