class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        vector<bool>dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(find(w.begin(), w.end(), s.substr(j, i - j)) != w.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()]; 
    }
};
