
class Solution {
public:
    void give(vector<int>& c, int t, int s, int i, vector<int>& p, vector<vector<int>>& a) {
        if (s > t) return;  // If the sum exceeds the target, return
        if (s == t) {       // If the sum equals the target, add the combination to results
            a.push_back(p);
            return;
        }
        if (i == c.size()) return;  // If index reaches the end, return

        // Include the current element and recurse
        p.push_back(c[i]);
        give(c, t, s + c[i], i, p, a);
        p.pop_back();  // Backtrack and remove the element

        // Exclude the current element and recurse
        give(c, t, s, i + 1, p, a);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        give(c, t, 0, 0, currentCombination, result);
        return result;
    }
};