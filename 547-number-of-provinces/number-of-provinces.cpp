class Solution {
public:
    int findCircleNum(vector<vector<int>>& is) {
        vector<vector<int>> a(is.size());
        int p = 1;
        for (int i = 0; i < is.size(); i++) {
            for (int j = 0; j < is[0].size(); j++) { 
                if (is[i][j] == 1) {
                    a[i].push_back(j);
                }
            }
        }

        vector<int> vis(is.size(), 0);
        queue<int> q;
        bool com = false;
        q.push(0);
        vis[0] = 1; 

        while (!com) {
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int i : a[node]) {
                    if (!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }

            com = true; 
            for (int i = 0; i < vis.size(); i++) {
                if (!vis[i]) {
                    p++;
                    q.push(i);
                    vis[i] = 1;  
                    com = false; 
                    break;
                }
            }
        }

        return p;
    }
};
