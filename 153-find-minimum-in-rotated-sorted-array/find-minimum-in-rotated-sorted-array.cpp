class Solution {
public:
    int findMin(vector<int>& n) {
        int l = 0, r = n.size() - 1;
        int a = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            a = min(a, min(n[l], min(n[mid], n[r])));
            
            if (n[l] < n[mid]) {
                l = mid + 1;
            } else if (n[mid] < n[r]) {
                r = mid - 1;
            } else {
                l++;
                r--;
            }
        }
        return a;
    }
};
