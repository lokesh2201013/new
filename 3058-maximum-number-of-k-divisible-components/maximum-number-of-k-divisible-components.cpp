class Solution {
public:
    int dfs(vector<vector<int>>& a, vector<int>& v, int k, int& c, int curr, int parent) {
        long long sum = v[curr];
        for (int neighbor : a[curr]) {
            if (neighbor != parent) {
                sum += dfs(a, v, k, c, neighbor, curr);
            }
        }
        sum %= k;
        if (sum == 0) c++;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& v, int k) {
        vector<vector<int>> a(n);
        for (const auto& edge : e) {
            a[edge[0]].push_back(edge[1]);
            a[edge[1]].push_back(edge[0]);
        }
        int c = 0;
        dfs(a, v, k, c, 0, -1);
        return c;
    }
};
