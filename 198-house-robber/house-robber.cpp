class Solution {
public:
    int rob(vector<int>& n) {
    if(n.empty()) return 0;
    int s=n.size();
      vector<int> dp(s, 0);
    if(s==1) return n[0];
    dp[0]=n[0];
    dp[1]=max(n[0],n[1]);
    for(int i=2 ; i<s ; i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+n[i]);
    }
    return dp[s-1];
    }
};
