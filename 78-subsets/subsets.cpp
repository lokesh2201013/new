class Solution {
public:
    void generateSubsets(int i, vector<int>& d, vector<int>& n, vector<vector<int>>& result) {
        if (i >= n.size()) {
            result.push_back(d);
            return;
        }
        
        // Include the current element
        d.push_back(n[i]);
        generateSubsets(i + 1, d, n, result);
        d.pop_back(); // Backtrack
        
        // Exclude the current element
        generateSubsets(i + 1, d, n, result);
    }
    
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>> result;
        vector<int> d; // Current subset
        
        generateSubsets(0, d, n, result);
        
        return result;
    }
};
