class Solution {
public:
    int longestSubarray(vector<int>& n, int li) {
        deque<int> i, d;
        int l = 0, m = 0;
        for (int r = 0; r < n.size(); r++) {
 
            while (!i.empty() && n[r] < i.back()) i.pop_back();
            i.push_back(n[r]);
            
            while (!d.empty() && n[r] > d.back()) d.pop_back();
            d.push_back(n[r]);
            while (d.front() - i.front() > li) {
                if (n[l] == d.front()) d.pop_front();
                if (n[l] == i.front()) i.pop_front();
                l++;
            }

            m = max(m, r - l + 1);
        }
        return m;
    }
};
