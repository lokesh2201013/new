class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int l = *max_element(w.begin(), w.end());
        int r = accumulate(w.begin(), w.end(), 0); 
        while (l < r) {
            int mid = l + (r - l) / 2;
            int c = 1, a = 0; 
            for (int i = 0; i < w.size(); i++) {
                if (a + w[i] > mid) {
                    c++;
                    a = 0;
                }
                a += w[i];
            }
            if (c > d) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};