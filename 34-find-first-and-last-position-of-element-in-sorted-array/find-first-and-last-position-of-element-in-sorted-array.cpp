class Solution {
private:
    int f(vector<int>& n, int t, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (n[mid] == t) {
                r = mid - 1;
            } else if (n[mid] > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int l(vector<int>& n, int t, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (n[mid] == t) {
                l = mid + 1;
            } else if (n[mid] > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
public:
    vector<int> searchRange(vector<int>& n, int t) {
        int first = f(n, t, 0, n.size() - 1);
        int last = l(n, t, 0, n.size() - 1);
        if (first <= last && n[first] == t && n[last] == t) {
            return {first, last};
        } else {
            return {-1, -1}; 
        }
    }
};
