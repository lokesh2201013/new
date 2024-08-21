
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++) {
            for(int node : adj[i]) {
                indeg[node]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(int neighbor : adj[node]) {
                indeg[neighbor]--;
                if(indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return count == n;
    }
};