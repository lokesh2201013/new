class Solution {
public:
    vector<int> rearrangeArray(vector<int>& n) {
        vector<int> o;
        vector<int> e;

        for (int i = 0; i < n.size(); i++) {
            if (n[i] < 0) {
                o.push_back(n[i]);
            } else {
                e.push_back(n[i]);
            }
        }

        n.clear();

        int size = min(e.size(), o.size());  // Use the size of the smaller vector
        for (int i = 0; i < size; i++) {
            n.push_back(e[i]);
            n.push_back(o[i]);
        }

        return n;
    }
};
