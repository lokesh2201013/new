class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> r;
        if (p.size() == 1) return p; 
        for (int i = 0; i < p.size()-1; i++) { 
            bool dis = false;
            for (int j = i + 1; j < p.size(); j++) { 
                if (p[j] <= p[i]) { 
                    r.push_back(p[i] - p[j]);
                    dis = true;
                    break;
                }
            }
            if (!dis) {
                r.push_back(p[i]);
            }
        }
        r.push_back(p[p.size()-1]);
        return r;
    }
};
