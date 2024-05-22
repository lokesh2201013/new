class Solution {
public:
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), m=queries.size();
        
        vector<int> dp(n, true);
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2) dp[i] = false;
        }
        
        vector<int> nearest_left_false(n, -1);
        int l_idx = -1;
        
        for(int i=1;i<n;i++){
            nearest_left_false[i] = l_idx;
            if(dp[i] == false) l_idx = i;
        }
        
        vector<int> nearest_right_false(n, n);
        int r_idx = (dp[n-1] == false ? n-1:n);
        
        for(int i=n-2;i>=0;i--){
            nearest_right_false[i] = r_idx;
            if(dp[i] == false) r_idx = i;
        }
        
        vector<bool> ans;
        for(vector<int> q : queries){
            int lb = q[0], ub = q[1];
            
            // nearest left false for UpperBound & nearest right false for LowerBound
            if(nearest_right_false[lb] <= ub || nearest_left_false[ub] > lb){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
        }
        return ans;
        
    }
};