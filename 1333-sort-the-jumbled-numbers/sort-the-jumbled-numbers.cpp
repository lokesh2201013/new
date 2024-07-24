class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& n) {
        map<long long, vector<int>> mp;
        
        for (int i = 0; i < n.size(); i++) {
            vector<int> t;
            int x = n[i];
            
            if (x == 0) {
                mp[m[x]].push_back(n[i]);
                continue;
            }
            
            while (x) {
                t.push_back(x % 10);
                x /= 10;
            }
            
            long long num = 0;
            for (int j = t.size() - 1; j >= 0; j--) {
                num = (num * 10) + m[t[j]];
            }
            
            mp[num].push_back(n[i]);
        }
        
        vector<int> a;
        for (auto it : mp) {
            for (auto x : it.second) {
                a.push_back(x);
            }
        }
        
        return a;
    }
};
