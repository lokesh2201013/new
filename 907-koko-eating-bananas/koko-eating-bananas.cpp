class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        sort(p.begin(), p.end());
        int l = 1; 
        int r = p.back();
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long hours = 0;
            
            for (int i = 0; i < p.size(); ++i) {
                hours += (p[i] + mid - 1) / mid; 
            }
            
            if (hours > h) {
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        
        return l;
    }
};
