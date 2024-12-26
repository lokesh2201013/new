class Solution {
public:
    int give(vector<int>& n, unordered_map<string, int>& memo, int i, int sum) {
        if (i == n.size()) {
            return sum == 0 ? 1 : 0;  
        }
        string key = to_string(i) + "_" + to_string(sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int add = give(n, memo, i + 1, sum + n[i]);
        int subtract = give(n, memo, i + 1, sum - n[i]);
        memo[key] = add + subtract;
        return memo[key];
    }

    int findTargetSumWays(vector<int>& n, int t) {
        unordered_map<string, int> memo; 
        return give(n, memo, 0, t);  
    }
};
