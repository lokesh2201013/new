class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& e) {
        map<int,vector<int>>m;
        m[e[0][1]].push_back(e[0][0]);
        for(int i=1 ; i<e.size(); i++){
           m[e[i][1]-e[i-1][1]].push_back(e[i][0]);
        }
        auto it=m.rbegin();
        vector<int>p=it->second;
        sort(p.begin(),p.end());

        return p[0];
    }
};