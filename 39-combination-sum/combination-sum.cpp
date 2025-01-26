class Solution {
public:
    void give(set<vector<int>>& a, vector<int>& c, int t, int s, int i, vector<int>& pa) {
        if (s > t || i == c.size()) {
            return;
        }
        if (s == t) {
            a.insert(pa);
            return; // Ensure no further recursion occurs after finding a valid combination
        }
        pa.push_back(c[i]);
        give(a, c, t, s + c[i], i, pa); // Include the current element
        pa.pop_back();
        give(a, c, t, s, i + 1, pa); // Move to the next element
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        set<vector<int>> a;
        vector<int> pa;
        give(a, c, t, 0, 0, pa);
        return vector<vector<int>>(a.begin(), a.end()); // Construct vector directly from the set
    }
};
