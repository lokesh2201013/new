class Solution {
public:
    void dfs(int n, vector<vector<int>>& adj, vector<int>& visited) {
        visited[n] = 1;
        for (auto it : adj[n]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& c) {
        int n = c.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;
    }
};
