class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1'000'000'007;
        vector<int> c(n, 1);  
        vector<int> temp(n, 0);  

        while (k--) {
            temp[0] = 1;
            for (int i = 1; i < c.size(); i++) {
                temp[i] = (temp[i-1] + c[i]) % MOD;  // Update `temp` based on previous values and take modulo
            }
            c = temp;
        }

        return c[n-1];  // Return the last element of `c`
    }
};